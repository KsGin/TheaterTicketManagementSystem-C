#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_DelByID.h"

int Account_Srv_DelByID(char userID[])
{
	USER *HEAD, *User;
	HEAD = Account_Srv_FetchAll();
	User = HEAD->NODE_NEXT;
	while (User != HEAD)
	{
		if (strcmp(userID,User->USER_ACCOUT) == 0)
		{
			User->NODE_NEXT->NODE_PREV = User->NODE_PREV;
			User->NODE_PREV->NODE_NEXT = User->NODE_NEXT;
		}
		User = User->NODE_NEXT;
	}
	Account_Perst_Update(HEAD);
	return 0;
}
