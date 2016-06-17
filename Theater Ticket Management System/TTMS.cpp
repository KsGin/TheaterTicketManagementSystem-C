// Theater Ticket Management System.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	if (pd_state() == 1)
	{
		SysLogin();
	}
	else
	{
		Account_UI_InitSys();
	}
    return 0;
}

