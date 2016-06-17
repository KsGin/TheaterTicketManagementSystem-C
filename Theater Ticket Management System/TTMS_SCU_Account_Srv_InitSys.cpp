#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_InitSys.h"

void Account_Srv_InitSys(char useraccount[], char  username[], char userpassword[], char password[])
{
	USER *HEAD;
	HEAD = (USER *)malloc(sizeof(USER));
	CREAT_LIST_HEAD_USER(HEAD);
	Account_Srv_Add(0, username, useraccount, userpassword, 0, HEAD);
	Account_Perst_Insert(HEAD);
	Account_Perst_Insert(HEAD->NODE_NEXT);
}
