#include "stdafx.h"
#include "GET_OC.h"

int GET_OC(int START_X, int START_Y /*开始坐标 */, int END_X, int END_Y /*结束坐标*/, int INTERVAR_Y /*间隔*/, int INTERVAR_X, char SHAPE[] /*标识符形状*/, int X_ON_OFF, int Y_ON_OFF)
{
	TTMS_GotoXY(START_X, START_Y);
	printf_s("%s", SHAPE);
	unsigned int key = 1;
	while (key != 13) {
		key = _getch();
		if (0 == key || 0xe0 == key) key |= _getch() << 8; {
			if (key == 27)
			{
				return 0;
			}
			if (Y_ON_OFF == 1)
			{
				if (key == 18656)
				{
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s("\b");
					}
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s(" ");
					}
					if (GET_CURSOR_Y() <= START_Y)
					{
						TTMS_GotoXY(GET_CURSOR_X() - strlen(SHAPE), END_Y);
						printf_s("%s", SHAPE);
					}
					else
					{
						TTMS_GotoXY(GET_CURSOR_X() - strlen(SHAPE), GET_CURSOR_Y() - INTERVAR_Y);
						printf_s("%s", SHAPE);
					}
				}
				else if (key == 20704)
				{
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s("\b");
					}
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s(" ");
					}
					if (GET_CURSOR_Y() >= END_Y)
					{
						TTMS_GotoXY(GET_CURSOR_X() - strlen(SHAPE), START_Y);
						printf_s("%s", SHAPE);
					}
					else
					{
						TTMS_GotoXY(GET_CURSOR_X() - strlen(SHAPE), GET_CURSOR_Y() + INTERVAR_Y);
						printf_s("%s", SHAPE);
					}
				}
			}
			if (X_ON_OFF == 1)
			{
				if (key == 19424)
				{
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s("\b");
					}
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s(" ");
					}
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s("\b");
					}
					if (GET_CURSOR_X() <= START_X)
					{
						TTMS_GotoXY(END_X, GET_CURSOR_Y());
						printf_s("%s", SHAPE);
					}
					else
					{
						TTMS_GotoXY(GET_CURSOR_X() - INTERVAR_X, GET_CURSOR_Y());
						printf_s("%s", SHAPE);
					}
				}
				if (key == 19936)
				{
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s("\b");
					}
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s(" ");
					}
					for (int i = 0; i < (int)strlen(SHAPE); i++)
					{
						printf_s("\b");
					}
					if (GET_CURSOR_X() >= END_X)
					{
						TTMS_GotoXY(START_X, GET_CURSOR_Y());
						printf_s("%s", SHAPE);
					}
					else
					{
						TTMS_GotoXY(GET_CURSOR_X() + INTERVAR_X, GET_CURSOR_Y());
						printf_s("%s", SHAPE);
					}
				}
			}
		}
	}
	return 1;
}
