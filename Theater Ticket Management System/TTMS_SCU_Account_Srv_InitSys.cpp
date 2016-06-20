#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_InitSys.h"

void Account_Srv_InitSys(char useraccount[], char  username[], char userpassword[], char password[])
{
	USER *HEAD = CREAT_LIST_HEAD_USER();
	Account_Srv_Add( username, useraccount, userpassword, 0, HEAD);
	Account_Perst_Insert(HEAD->NODE_NEXT);
}
