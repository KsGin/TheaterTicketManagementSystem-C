#include "stdafx.h"
#include "TTMS_SCU_Account_UI_QUE.h"

void Account_UI_Que(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	TTMS_GotoXY(52, 6);
	printf_s("没人来大剧院");
	TTMS_GotoXY(43, 9);
	printf_s("%s您好，请输入要查找的用户姓名", user->USER_NAME);
	TTMS_GotoXY(54, 11);
	char FindName[USER_LEN];
	scanf_s("%s", FindName, USER_LEN);
	USER *UserFind = Account_Perst_FetchByName(FindName);
	if (!UserFind)
	{
		TTMS_GotoXY(41, 24);
		printf_s("没有找到此系统用户，请Enter重试或Esc返回");
		Account_Srv_Back(user);
	}
	TTMS_GotoXY(47, 13);
	printf_s("姓名:%s", UserFind->USER_NAME);
	TTMS_GotoXY(47, 15);
	printf_s("账号:%s", UserFind->USER_ACCOUT);
	TTMS_GotoXY(47, 17);
	printf_s("身份:");
	if (UserFind->power == 1)
	{
		printf_s("售票经理");
	}
	else if (UserFind->power == 2)
	{
		printf_s("售票员");
	}
	else if (UserFind->power == 0)
	{
		printf_s("系统管理员");
	}
	Account_Srv_Back(user);
	char key[15];
	strcpy_s(key, 15, GET_KEY());
	if (strcmp(key, "Esc") == 0)
	{
		Account_UI_MgtEntry(user);
	}
	else
	{
		Account_UI_Que(user);
	}
}
