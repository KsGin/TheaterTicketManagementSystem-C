#include "stdafx.h"
#include "TTMS_GotoXY.h"

void TTMS_GotoXY(int x, int y) {
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
