#include "ColorShaderClass.h"



ColorShaderClass::ColorShaderClass()
{
	m_vertexShader = 0;
	m_pixelShader = 0;
	m_layout = 0;
	m_matrixBuffer = 0;
}

ColorShaderClass::ColorShaderClass(const ColorShaderClass & other)
{
}


ColorShaderClass::~ColorShaderClass()
{
}

bool ColorShaderClass::Initiallize(ID3D11Device * device, HWND hWnd)
{
	bool result;
	result = InitializeShader(device, hWnd, L"../AutumnMorningEngine/Color.vs", L"../AutumnMorningEngine/Color.ps"); 
	if (!result)
	{
		return false;
	}

	return true;
}

void ColorShaderClass::Shutdown()
{
	//Shutdown the vertex and pixel shaders as well as the related objects
	ShutdownShader();
	return;
}

bool ColorShaderClass::Render(ID3D11DeviceContext * deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projctionMatrix)
{
	bool result;
	//Set the shader parameters that is will use for rendering
	result = SetShaderParameters(deviceContext, worldMatrix, viewMatrix, projctionMatrix);
	if (!result)
	{
		return false;
	}

	//Now render the preparend buffers with the shader
	RenderShader(deviceContext, indexCount);

	return true;
}

bool ColorShaderClass::InitializeShader(ID3D11Device * device, HWND hWnd, WCHAR * vsFilename, WCHAR * psFilename) //<- LPCSTR *로 수정(원본 Char *)
{
	HRESULT result;
	ID3D10Blob* errorMessage;
	ID3D10Blob* vertexShaderBuffer;
	ID3D10Blob* pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[2];
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;

	//Initialize the pointers this function will use to null
	errorMessage = 0;
	vertexShaderBuffer = 0;
	pixelShaderBuffer = 0;

	//Complie the vertex shaer code 
	result = D3DX11CompileFromFile((LPCSTR)vsFilename, NULL, NULL, "ColorVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL,&vertexShaderBuffer,&errorMessage,NULL);
	if (FAILED(result))
	{
		//If the shader failed to complie it should have writen something
		if (errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, hWnd, vsFilename);
		}
		//If there was nothing in the error message then it simply could not find the file itself
		else
		{
			MessageBox(hWnd, (LPCSTR)psFilename, "Missing Shader File", MB_OK);
		}

		return false;
	}

	//Create the vertex shader from the buffer
	result = device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), NULL, &m_vertexShader);
	if (FAILED(result))
	{
		return false;
	}

	//Create the pixel shader from the buffer
	result = device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), NULL, &m_pixelShader);
	if (FAILED(result))
	{
		return false;
	}

	//Now setup the layout of the data that goes into the shader
	//This setup needs to match the VertexType stucture in the ModelClass and in the shader
	polygonLayout[0].SemanticName = "POSITION";
	polygonLayout[0].SemanticIndex = 0;
	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[0].InputSlot = 0;
	polygonLayout[0].InstanceDataStepRate = 0;

	polygonLayout[1].SemanticName = "COLOR";
	polygonLayout[1].SemanticIndex = 0;
	polygonLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	polygonLayout[1].InputSlot = 0;
	polygonLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[1].InstanceDataStepRate = 0;

	//Get a count of the elements in the layout
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	//Create the vertex input layout
	result = device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), &m_layout);
	if (FAILED(result))
	{
		return false;
	}

	//Release the vertex shader buffer and pixel shader buffer since they are no longer needed
	vertexShaderBuffer->Release();
	vertexShaderBuffer = 0;


	return true;
}

void ColorShaderClass::ShutdownShader()
{
}

void ColorShaderClass::OutputShaderErrorMessage(ID3D10Blob *, HWND, WCHAR *)
{
}

bool ColorShaderClass::SetShaderParameters(ID3D11DeviceContext *, D3DXMATRIX, D3DMATRIX, D3DMATRIX)
{
	return false;
}

void ColorShaderClass::RenderShader(ID3D11DeviceContext *, int)
{
}
