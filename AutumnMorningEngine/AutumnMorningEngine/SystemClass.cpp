#include "SystemClass.h"



SystemClass::SystemClass()
{
	m_Input = 0;
	m_Graphics = 0;
}


SystemClass::~SystemClass()
{
}

SystemClass::SystemClass(const SystemClass& other)
{

}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY: // 창을 끌때 메시지가 전달됨.
		PostQuitMessage(0);// 스레드가 종료 요청을 했다는 것을 시스템에 알린다.
		return 0;
	case WM_CLOSE: // 창을 끌때 메시지가 전달됨.
		PostQuitMessage(0);// 스레드가 종료 요청을 했다는 것을 시스템에 알린다.
		return 0;
	default:
		return ApplicationHandle->MessageHandler(hWnd, msg, wParam, lParam);
	}
	
}

LRESULT CALLBACK SystemClass::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
	case WM_KEYDOWN:
		m_Input->KeyDown((unsigned int)wparam);
		return 0;
	case WM_KEYUP:
		m_Input->KeyUp((unsigned int)wparam);
		return 0;
	default:
		return DefWindowProc(hwnd, umsg, wparam, lparam);
	
	}
}

bool SystemClass::Initialize()
{
	int screenWidth, screenHeight;
	bool result;

	m_applicationName	= "AutumnMorning Engine";
	m_hInstance = GetModuleHandle(NULL);
	ApplicationHandle = this;
	InitializeWindows(screenWidth, screenHeight);

	m_Input = new InputClass;
	if (!m_Input)
	{
		return false;
	}
	m_Input->Initialize();

	m_Graphics = new GraphicsClass;
	if (!m_Graphics)
	{
		return false;
	}
	result = m_Graphics->Initialize(screenWidth, screenHeight, m_hWnd);
	if (!result)
	{
		return false;
	}
	
	return true;
}

void SystemClass::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIconSm = wc.hIcon;
	wc.hInstance = m_hInstance;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszMenuName = MAKEINTRESOURCE(109);
	wc.lpszClassName = m_applicationName;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);


	RegisterClassEx(&wc);

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CXSCREEN);

	DEVMODE dmScreenSettings;
	int posX, posY;
	if (FULL_SCREEN)
	{
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		posX = posY = 0;
	}
	else
	{
		screenWidth = 800;
		screenHeight = 600;

		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	
	m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName,
		m_applicationName,
		WS_OVERLAPPEDWINDOW,// | WS_DLGFRAME | WS_CLIPCHILDREN | WS_POPUP, // <- 이게 뭔지 모르니 검색할것
		posX, posY, screenWidth, screenHeight,
		GetDesktopWindow(), nullptr, m_hInstance, nullptr);
		//WS_OVERLAPPEDWINDOW : 상단 바 있음 (아이콘, 파일명,최소화,최대화, 종료 버튼 있음)
		//WS_CLIPSIBLINGS :
		//WS_CLIPCHILDREN :
		//WS_POPUP : 상단 바 없어짐
	ShowWindow(m_hWnd, SW_SHOW);
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);

	ShowCursor(true);

	return;
}

void SystemClass::Shutdown()
{
	if (m_Graphics)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
		m_Graphics = 0;
	}

	if (m_Input)
	{
		delete m_Input;
		m_Input = 0; 
	}

	ShutdownWindows();
	return;
}

void SystemClass::ShutdownWindows()
{
	ShowCursor(true);
	if(FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	DestroyWindow(m_hWnd);
	m_hWnd = NULL;

	UnregisterClass(m_applicationName, m_hInstance);
	m_hInstance = NULL;

	ApplicationHandle = NULL;

	return;

}

void SystemClass::Run()
{
	MSG msg;
	bool done, result;

	ZeroMemory(&msg, sizeof(MSG));

	done = false;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			result = Frame();
			if (!result)
			{
				done = true;
			}
		}
	}
}

bool SystemClass::Frame()
{
	bool result;
	
	if (m_Input->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	result = m_Graphics->Frame();
	if (!result)
	{
		return false;
	}

	return true;
}