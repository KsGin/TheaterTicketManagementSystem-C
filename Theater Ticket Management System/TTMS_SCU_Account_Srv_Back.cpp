#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_Back.h"

void Account_Srv_Back(USER * user)
{
	TTMS_GotoXY(45, 3);
	printf_s("按任意键返回管理员%s的菜单", user->USER_NAME);
	_getch();
	Account_UI_MgtEntry(user);
}
