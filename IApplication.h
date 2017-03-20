#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

class IApplication
{
public:
	IApplication();
	virtual ~IApplication();

	bool Create();
	void Run();


private:
	static HWND MakeWindow(int iWidth, int iHeight, const wchar_t* pTitle);

	HWND	m_Window;

};