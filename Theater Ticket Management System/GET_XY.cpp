#include "stdafx.h"
#include "GET_XY.h"

int GET_CURSOR_X() {
	HANDLE gh_std_out;
	gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(gh_std_out, &bInfo);
	return bInfo.dwCursorPosition.X + 1;
}

int GET_CURSOR_Y() {
	HANDLE gh_std_out;
	gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(gh_std_out, &bInfo);
	return bInfo.dwCursorPosition.Y + 1;
}