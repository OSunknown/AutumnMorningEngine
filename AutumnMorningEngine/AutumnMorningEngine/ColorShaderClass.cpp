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
	result = InitializeShader(device, hWnd, (LPCSTR *)"../Engine/Color.vs", (LPCSTR *)"../Engine/Color.ps"); //<- 여기 에러뜰듯..?
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

bool ColorShaderClass::InitializeShader(ID3D11Device * device, HWND hWnd, LPCSTR * vsFilename, LPCSTR * psFilename) //<- LPCSTR *로 수정(원본 Char *)
{
	HRESULT result;
	ID3D10Blob* errorMessage;
	ID3D10Blob* vertexShaderBuffer;
	ID3D10Blob* pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC polyconLayout[2];
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;

	//Initialize the pointers this function will use to null
	errorMessage = 0;
	vertexShaderBuffer = 0;
	pixelShaderBuffer = 0;

	//Complie the vertex shaer code 
	result = D3DX11CompileFromFile(*vsFilename, NULL, NULL, "ColorVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL,&vertexShaderBuffer,&errorMessage,NULL);
	
	return false;
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
