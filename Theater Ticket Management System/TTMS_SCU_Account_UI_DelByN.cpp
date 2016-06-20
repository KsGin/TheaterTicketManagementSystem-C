#include "stdafx.h"
#include "TTMS_SCU_Account_UI_DelByN.h"

void Account_UI_DeleteByName(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	TTMS_GotoXY(52, 6);
	printf_s("没人来大剧院");
	TTMS_GotoXY(43, 9);
	printf_s("%s您好，请输入要删除的用户ID", user->USER_NAME);
	TTMS_GotoXY(54, 11);
	char delname[USER_LEN];
	scanf_s("%s",delname,USER_LEN);
	if (Account_Perst_CheckAccout(delname) == 1)
	{
		USER *user = Account_Perst_FetchByName(delname);
		Account_Perst_DelByName(delname);
		TTMS_GotoXY(52, 18);
		printf_s("删除成功");
		Account_Srv_Back(user);
	}
	else
	{
		TTMS_GotoXY(43, 15);
		printf_s("没有找到此系统用户，请Enter重试或Esc返回");
	}
	char key[15];
	strcpy_s(key,15, GET_KEY());
	if (strcmp(key,"Esc") == 0)
	{
		Account_UI_MgtEntry(user);
	}
	else
	{
		Account_UI_DeleteByName(user);
	}
}
