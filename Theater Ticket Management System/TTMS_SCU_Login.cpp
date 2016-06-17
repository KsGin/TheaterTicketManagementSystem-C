#include "stdafx.h"
#include "TTMS_SCU_Login.h"

void SysLogin()
{
	system("cls");
	char useraccount[USER_LEN], userpassword[USER_LEN];
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(54, 6);
	printf_s("没人来剧院");
	TTMS_GotoXY(55, 9);
	printf_s("用户登录");
	TTMS_GotoXY(50, 11);
	printf_s("账号:");
	TTMS_GotoXY(50, 13);
	printf_s("密码:");
	TTMS_GotoXY(56, 11);
	INPUT_ACCOUT(useraccount, USER_LEN);
	TTMS_GotoXY(56, 13);
	INPUT_PASSWORD(userpassword, USER_LEN);
	if (Account_Perst_CheckAccFile(useraccount) == 0)
	{
		TTMS_GotoXY(52, 18);
		printf_s("没有找到此账号！");
		_getch();
		SysLogin();
		TTMS_GotoXY(52, 20);
	}
	else
	{
		int flag = Account_Srv_Verify(useraccount, userpassword);
		if (flag == 1)
		{
			USER *user = Account_Srv_FetchByAccount(useraccount);
			TTMS_GotoXY(55, 20);
			printf_s("登陆成功");
			TTMS_GotoXY(52, 22);
			Account_UI_MgtEntry(user);
		}
		if (flag == 0)
		{
			TTMS_GotoXY(55, 20);
			printf_s("密码错误");
			_getch();
			SysLogin();
		}
	}
}
