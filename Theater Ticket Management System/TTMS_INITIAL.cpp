#include "stdafx.h"
#include "TTMS_INITIAL.h"

void TTMS_INITIAL() {
	for (int i = 22; i < 100; i++) {
		TTMS_GotoXY(i, 4);
		printf_s("_");
		TTMS_GotoXY(i, 25);
		printf_s("_");
		TTMS_GotoXY(i, 22);
		printf_s("_");
	}
	for (int i = 5; i <= 25; i++) {
		TTMS_GotoXY(21, i);
		printf_s("|");
		TTMS_GotoXY(100, i);
		printf_s("|");
	}
	TTMS_GotoXY(55, 13);
	printf_s("正在初始化...");
	for (int i = 0; i < 5; i++) {
		TTMS_GotoXY(58 + i, 15);
		putchar('*');
		TTMS_GotoXY(59, 24);
		printf_s("%d%%", i * 25);
		Sleep(1000);
	}
}