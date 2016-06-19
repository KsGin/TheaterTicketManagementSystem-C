#include "stdafx.h"
#include "TTMS_SCU_Account_UI_InitSys.h"

void Account_UI_InitSys()
{
	TTMS_GotoXY(42, 10);
	printf_s("当前系统未初始化，请按任意键初始化系统");
	_getch();
	system("cls");
	char useraccount[USER_LEN],username[USER_LEN], userpassword[USER_LEN],password[USER_LEN];
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(54, 6);
	printf_s("没人来剧院");
	TTMS_GotoXY(55, 9);
	printf_s("设置系统管理员");
	TTMS_GotoXY(50, 11);
	printf_s("姓名:");
	TTMS_GotoXY(50, 13);
	printf_s("账号:");
	TTMS_GotoXY(50, 15);
	printf_s("密码:");
	TTMS_GotoXY(50, 17);
	printf_s("确认密码:");
	TTMS_GotoXY(56, 11);
	scanf_s("%s",username,15);
	TTMS_GotoXY(56, 13);
	INPUT_ACCOUT(useraccount, USER_LEN);
	TTMS_GotoXY(56, 15);
	INPUT_PASSWORD(userpassword, USER_LEN);
	TTMS_GotoXY(59, 17);
	INPUT_PASSWORD(password, USER_LEN);
	if (strcmp(userpassword,password) == 0)
	{
		system("cls");
		TTMS_INITIAL();
		Account_Srv_InitSys(useraccount, username, userpassword, password);
		Main_UI_MgtEntry(Account_Perst_FetchByAccount(useraccount));
	}
}
