/*
* main.cpp
* entry point for a superduper game engine
*/

#include "IApplication.h"

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR PcmdLine, int nCmdShow)
{
	IApplication* pApp = new IApplication;

	if (!pApp -> Create())
	{
		::MessageBox(NULL, L"App start failed... sorry", L"Guru Meditation", MB_OK);
		return 0;
	}

	pApp->Run();
	delete pApp;
	return 0;
}

