#include "stdafx.h"
#include "TTMS_SCU_Account_UI_ModP.h"

void Account_UI_ModPassword(USER *user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("修改用户密码");
	TTMS_GotoXY(45, 9);
	printf_s("请输入原密码:");
	TTMS_GotoXY(45, 11);
	printf_s("请输入新密码:");
	TTMS_GotoXY(45, 13);
	printf_s("请确认新密码:");
	char OldPassword[USER_LEN], NewPassword1[USER_LEN], NewPassword2[USER_LEN];
	TTMS_GotoXY(58, 9);
	INPUT_PASSWORD(OldPassword,USER_LEN);
	TTMS_GotoXY(58, 11);
	INPUT_PASSWORD(NewPassword1, USER_LEN);
	TTMS_GotoXY(58, 13);
	INPUT_PASSWORD(NewPassword2, USER_LEN);
	if (strcmp(OldPassword,user->USER_PASSWORD) == 0)
	{
		if (strcmp(NewPassword1,NewPassword2) == 0)
		{
			if (Account_Srv_ModPassword(user, NewPassword1) == 1) {
				TTMS_GotoXY(53, 18);
				printf_s("修改成功,任意键返回");
				_getch();
				if (user->power == 0)
				{
					Account_UI_MgtEntry(user);
				}
				else {
					Main_UI_MgtEntry(user);
				}
			}
			_getch();
		}
		else
		{
			TTMS_GotoXY(53, 18);
			printf_s("两次不一致");
			_getch();
			if (user->power == 0)
			{
				Account_UI_MgtEntry(user);
			}
			else {
				Main_UI_MgtEntry(user);
			}
		}
	}
	else
	{
		TTMS_GotoXY(53, 18);
		printf_s("原密码输入错误");
		_getch();
		if (user->power == 0)
		{
			Account_UI_MgtEntry(user);
		}
		else {
			Main_UI_MgtEntry(user);
		}
	}
}
