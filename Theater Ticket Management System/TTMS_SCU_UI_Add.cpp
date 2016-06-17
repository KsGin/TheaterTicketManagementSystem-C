#include "stdafx.h"
#include "TTMS_SCU_UI_Add.h"

void Account_UI_Add()
{
	USER *user;
	user = (USER*)malloc(sizeof(USER));
	system("cls");
	int power = 1;
	BIOS_GOTO_BOX(22,100,5,25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(55, 6);
	printf_s("增加新用户");
	TTMS_GotoXY(50, 9);
	printf_s("姓名:");
	TTMS_GotoXY(50, 11);
	printf_s("账号:");
	TTMS_GotoXY(50, 13);
	printf_s("密码:");
	TTMS_GotoXY(50, 15);
	printf_s("售票经理");
	TTMS_GotoXY(62, 15);
	printf_s("售票员");
	TTMS_GotoXY(47,15);
	printf_s("▇");
	TTMS_GotoXY(55, 9);
	scanf_s("%s", user->USER_NAME, USER_LEN);
	TTMS_GotoXY(55, 11);
	INPUT_ACCOUT(user->USER_ACCOUT, USER_LEN);
	TTMS_GotoXY(55, 13);
	INPUT_PASSWORD(user->USER_PASSWORD, USER_LEN);
	GET_OC(47, 15, 59, 15, 0, 12, "▇", 1, 0);
	if (GET_CURSOR_X() == 47)
	{
		user->power = 1;
	}
	else if (GET_CURSOR_X() == 59)
	{
		user->power = 2;
	}
	user->NODE_NEXT = NULL;
	user->NODE_PREV = NULL;
	Account_Perst_Insert(user);
	TTMS_GotoXY(55, 18);
	printf_s("增加成功");
	TTMS_GotoXY(55, 20);
}
