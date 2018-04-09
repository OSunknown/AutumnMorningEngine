
///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define WIN32_LEAN_AND_MEAN

#pragma once
//////////////
// INCLUDES //
//////////////
#include <Windows.h>
#include "GraphicsClass.h"
#include "InputClass.h"

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int& , int& );
	void ShutdownWindows();

private:

	LPCWSTR m_applicationName;
	HINSTANCE  m_hInstance;
	HWND m_hWnd;
	InputClass* m_Input;
	GraphicsClass* m_Graphics;

};

/////////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/////////////
// GLOBALS //
/////////////
static SystemClass* ApplicationHandle = 0;
