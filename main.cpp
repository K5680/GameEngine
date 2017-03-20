/*
* main.cpp
* entry point for a superduper game engine
*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR PcmdLine, int nCmdShow)
{
	::MessageBox(NULL, L"Hello Game Engine", L"HELLO", MB_OK);
	return 0;
}

