#include "stdafx.h"
#include "BIOS_GOTO_BOX.h"

void BIOS_GOTO_BOX(int x1, int x2, int y1, int y2) {
	for (int i = x1 + 1; i < x2; i++) {
		TTMS_GotoXY(i, y1 - 1);
		printf_s("_");
		TTMS_GotoXY(i, y2);
		printf_s("_");
	}
	for (int i = y1; i <= y2; i++) {
		TTMS_GotoXY(x1, i);
		printf_s("|");
		TTMS_GotoXY(x2, i);
		printf_s("|");
	}
}

