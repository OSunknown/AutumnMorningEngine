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
	result = InitializeShader(device, hWnd, L"../Engine/Color.vs", L"../Engine/Color.ps"); //<- 여기 에러뜰듯..?
	return false;
}
