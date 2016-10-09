#include "stdafx.h"
#include "TTMS_SCU_Studio_UI_MgtEnt.h"

void Studio_UI_MgtEntry(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("欢迎回来,%s", user->USER_NAME);
	TTMS_GotoXY(45, 24);
	printf_s("按UP/DOWN选择,ENTER确认,ESC返回上一层");
	BIOS_GOTO_BOX(22, 100, 23, 22);
	TTMS_GotoXY(47, 9);
	printf_s("NO1:添加新演出厅");
	TTMS_GotoXY(47, 11);
	printf_s("NO2:修改演出厅");
	TTMS_GotoXY(47, 13);
	printf_s("NO3:删除演出厅");
	TTMS_GotoXY(47, 15);
	printf_s("NO4:座位管理");
	TTMS_GotoXY(47, 17);
	printf_s("No5:查看演出厅");
	TTMS_GotoXY(47, 19);
	auto flag = GET_OC(44, 9, 44, 17, 2, 1, "->", 0, 1);
	if (flag ==1)
	{
		switch (GET_CURSOR_Y())
		{
		case 9: Studio_UI_add(user); break;
		case 11:Studio_UI_Mod(user); break;
		case 13:Studio_UI_Delete(user); break;
		case 15:Seat_UI_MgtEntry(user); break;
		case 17:Studio_UI_Browe(user); break;
		default:
			break;
		}
	}
	else if (flag == 0)
	{
		Main_UI_MgtEntry(user);
	}
}
