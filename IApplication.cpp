
#include "IApplication.h"

IApplication::IApplication()
{
}


IApplication::~IApplication()
{
}


bool IApplication::Create()
{
	return true;
}

void IApplication::Run()
{
	
}

HWND IApplication::MakeWindow(int iWidth, int iHeight, const wchar_t* pTitle)
{
	HINSTANCE hInst = ::GetModuleHandle(NULL);
	DWORD windowStyle = 0;

	windowStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

	WNDCLASS wc;
	memset(&wc, 0, sizeof(WNDCLASS));	// täytetään structi nollilla kokonaan
	
	wc.style = CS_HREDRAW | CS_VREDRAW;  // horiz & vert. redraw käytössä
	wc.lpfnWndProc = NULL; // TODO: window procedure
	wc.hInstance = hInst;
	wc.hIcon = ::LoadIcon(hInst, 0);
	wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)::GetStockObject(BLACK_BRUSH);
	wc.lpszClassName = L"GAMEENGINE_WNDCLASS";

	if (!::RegisterClass(&wc))
	{
		return NULL;
	}

	// create the window

	HWND window = ::CreateWindow(wc.lpszClassName, pTitle, windowStyle, CW_USEDEFAULT, CW_USEDEFAULT, iWidth, iHeight, NULL, NULL, hInst, NULL);

	if (!window)
	{
		::OutputDebugString(L"Failed to create window, exiting...");
		return 0;
	}

	::SetWindowLong(window, GWL_STYLE, windowStyle);
	RECT clientArea = { 0, 0, iWidth, iHeight };
	::AdjustWindowRectEx(&clientArea, windowStyle, FALSE, 0);
	::SetWindowPos(window, NULL, 0, 0, iWidth, iHeight, SWP_NOZORDER | SWP_NOMOVE | SWP_SHOWWINDOW);

	::UpdateWindow(window);
	::ShowWindow(window, SW_SHOWNORMAL);
	
	return window;
}
