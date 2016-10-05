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
	printf_s("密码(1/3):");
	TTMS_GotoXY(56, 11);
	INPUT_ACCOUT(useraccount, USER_LEN);
	TTMS_GotoXY(60, 13);
	INPUT_PASSWORD(userpassword, USER_LEN);
	if (Account_Perst_CheckAccout(useraccount) == 0)
	{
		TTMS_GotoXY(52, 18);
		printf_s("没有找到此账号！");
		_getch();
		SysLogin();
		TTMS_GotoXY(52, 20);
	}
	else
	{
		auto count = 1;
		auto flag = Account_Srv_Verify(useraccount, userpassword);
		while(count <= 3)
		{
			if (Account_Srv_Verify(useraccount , userpassword))
			{
				auto user = Account_Perst_FetchByAccount(useraccount);
				TTMS_GotoXY(55, 20);
				printf_s("登陆成功");
				TTMS_GotoXY(52, 22);
				Main_UI_MgtEntry(user);
			}
			else {
				if (count == 3)
				{
					TTMS_GotoXY(52, 20);
					printf_s("密码错误次数太多!");
					TTMS_GotoXY(55, 3);
					exit(1);
				}
				TTMS_GotoXY(55, 20);
				printf_s("密码错误");
				TTMS_GotoXY(50, 13+count*2);
				printf_s("密码(%d/3):                                  ",count+1);
				TTMS_GotoXY(60, 13+count*2);
				INPUT_PASSWORD(userpassword, USER_LEN);
				count++;
			}
		}
		TTMS_GotoXY(55, 3);
		exit(1);
	}
}
