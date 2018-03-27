#include "GraphicsClass.h"



GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
}


GraphicsClass::~GraphicsClass()
{
}

GraphicsClass::GraphicsClass(const GraphicsClass& other)
{

}

bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hWnd)
{
	bool result;

	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hWnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hWnd, "Could not initialize Direct3D", "Error", MB_OK);
		return false;
	}
	return true;
}

void GraphicsClass::Shutdown()
{
	return;
}

bool GraphicsClass::Frame()
{
	return true;
}

bool GraphicsClass::Render()
{
	m_D3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	m_D3D->EndScene();
	return true;
}