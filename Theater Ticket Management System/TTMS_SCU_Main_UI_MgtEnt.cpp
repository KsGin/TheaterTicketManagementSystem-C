#include "stdafx.h"
#include "TTMS_SCU_Account_UI_MgtEnt.h"

void Main_UI_MgtEntry(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("欢迎回来,%s", user->USER_NAME);
	TTMS_GotoXY(45, 24);
	printf_s("按UP/DOWN选择,ENTER确认,ESC注销登录");
	BIOS_GOTO_BOX(22, 100, 23, 22);
	if (user->power == 0)
	{
		TTMS_GotoXY(47, 9);
		printf_s("No1:系统用户管理");
		TTMS_GotoXY(47, 11);
		printf_s("No2:演出厅管理");
		TTMS_GotoXY(47, 13);
		printf_s("No3:恢复出厂化");
		if (GET_OC(44, 9, 44, 13, 2, 1, "->", 0, 1) == 1) {
			switch (GET_CURSOR_Y())
			{
			case 9:Account_UI_MgtEntry(user);
			case 11:Studio_UI_MgtEntry(user);
			case 13:
				system("cls");
				remove("Account.dat");
				remove("Studio.dat");
				remove("EntityKey.dat");
				TTMS_INITIAL();
				exit(0);
			default:
				break;
			}
		}
		else {
			SysLogin();
		}
	}
}
