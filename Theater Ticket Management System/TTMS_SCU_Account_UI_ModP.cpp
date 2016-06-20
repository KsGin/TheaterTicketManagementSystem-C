#include "stdafx.h"
#include "TTMS_SCU_Account_UI_ModP.h"

void Account_UI_ModPassword(USER *user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(50, 6);
	printf_s("修改用户密码");
	TTMS_GotoXY(47, 9);
	printf_s("请输入原密码:");
	TTMS_GotoXY(47, 11);
	printf_s("请输入新密码:");
	TTMS_GotoXY(47, 13);
	printf_s("请确认新密码:");
	char OldPassword[USER_LEN], NewPassword1[USER_LEN], NewPassword2[USER_LEN];
	TTMS_GotoXY(50, 9);
	INPUT_PASSWORD(OldPassword,USER_LEN);
	TTMS_GotoXY(50, 11);
	INPUT_PASSWORD(NewPassword1, USER_LEN);
	TTMS_GotoXY(50, 13);
	INPUT_PASSWORD(NewPassword2, USER_LEN);
	if (strcmp(OldPassword,user->USER_PASSWORD) == 0)
	{
		if (strcmp(NewPassword1,NewPassword2) == 0)
		{
			
		}
		else
		{
			TTMS_GotoXY(50, 18);
			printf_s("两次不一致");
		}
	}
	else
	{
		printf_s("原密码输入错误");
	}
}
