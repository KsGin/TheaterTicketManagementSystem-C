#include "stdafx.h"
#include "TTMS_SCU_Account_UI_DelByN.h"

void Account_UI_DeleteByName(USER * Admini)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	TTMS_GotoXY(52, 6);
	printf_s("没人来大剧院");
	TTMS_GotoXY(43, 9);
	printf_s("%s您好，请输入要删除的用户ID", Admini->USER_NAME);
	TTMS_GotoXY(54, 11);
	char delname[USER_LEN];
	scanf_s("%s",delname,USER_LEN);
	if (Account_Perst_CheckAccout(delname) == 1)
	{
		USER *user = Account_Perst_FetchByName(delname);
		TTMS_GotoXY(47, 13);
		printf_s("姓名:%s", user->USER_NAME);
		TTMS_GotoXY(47, 15);
		printf_s("账号:%s", user->USER_ACCOUT);
		TTMS_GotoXY(47, 17);
		printf_s("身份:");
		if (user->power == 1)
		{
			printf_s("售票经理");
		}
		else if (user->power == 2)
		{
			printf_s("售票员");
		}
		else if (user->power == 0)
		{
			printf_s("系统管理员");
		}
		TTMS_GotoXY(44, 19);
		printf_s("Enter确认删除,其他键退出");
		char Chiose[USER_LEN];
		strcpy_s(Chiose, USER_LEN, GET_KEY());
		if (strcmp(Chiose,"Enter") == 0)
		{
			Account_Perst_DelByName(delname);
			TTMS_GotoXY(53, 20);
			printf_s("删除成功");
			Account_Srv_Back(Admini);
		}
		else {
			TTMS_GotoXY(53, 20);
			printf_s("取消成功");
			Account_Srv_Back(Admini);
		}
	}
	else
	{
		TTMS_GotoXY(43, 20);
		printf_s("没有找到此系统用户，请Enter重试或Esc返回");
	}
	char key[15];
	strcpy_s(key,15, GET_KEY());
	if (strcmp(key,"Esc") == 0)
	{
		Account_UI_MgtEntry(Admini);
	}
	else
	{
		Account_UI_DeleteByName(Admini);
	}
}
