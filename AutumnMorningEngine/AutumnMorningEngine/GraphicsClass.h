#pragma once 

//////////////
// INCLUDES //
//////////////
#include <Windows.h>
#include "D3DClass.h"
#include "Cameraclass.h"
#include "ModelClass.h"
//#include "ColorShaderClass.h"
#include "TextureShaderClass.h"
#include "LightClass.h"
#include "LightShaderClass.h"

#include "bitmapclass.h"

#include"Debug.h"
/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render(float);

private:
	D3DClass * m_D3D;
	CameraClass * m_Camera;
	ModelClass* m_Model;
//	ColorShaderClass * m_ColorShader;
	TextureShaderClass* m_TextureShader;
	LightShaderClass* m_LightShader;
	LightClass* m_Light;

	BitmapClass* m_Bitmap;
};

