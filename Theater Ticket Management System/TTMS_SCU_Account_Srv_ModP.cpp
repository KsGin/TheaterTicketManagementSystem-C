#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_ModP.h"

int Account_Srv_ModPassword(USER *user, char NewPassword[])
{
	if (Account_Perst_ModPassword(user,NewPassword) == 1)
	{
		return 1;
	}
	return 0;
}
