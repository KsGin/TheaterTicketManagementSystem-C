#include "stdafx.h"
#include "TTMS_SCU_Account_Prest_Insert.h"

void Account_Perst_Insert(USER * user)
{
	FILE *fp;
	errno_t err;
	err = fopen_s(&fp, "Account.dat", "ab+");
	if (err != 0)
	{
		printf_s("´íÎó:%d", err);
	}
	fwrite(user, sizeof(USER), 1, fp);
	fclose(fp);
}
