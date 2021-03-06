#pragma once
#include <D3D11.h>
#include <D3DX11async.h>
#include <fstream>
#include "Math.h"
using namespace std;

class ColorShaderClass
{
private:
	struct MatrixBufferType
	{
		Matrix4 world;
		Matrix4 view;
		Matrix4 projection;
	};

public:
	ColorShaderClass();
	ColorShaderClass(const ColorShaderClass&);
	~ColorShaderClass();

	bool Initiallize(ID3D11Device *, HWND);
	void Shutdown();
	bool Render(ID3D11DeviceContext*, int, Matrix4, Matrix4, Matrix4);
private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, Matrix4, Matrix4, Matrix4);
	void RenderShader(ID3D11DeviceContext*, int);
private:
	ID3D11VertexShader * m_vertexShader;
	ID3D11PixelShader * m_pixelShader;
	ID3D11InputLayout * m_layout;
	ID3D11Buffer * m_matrixBuffer;
};

