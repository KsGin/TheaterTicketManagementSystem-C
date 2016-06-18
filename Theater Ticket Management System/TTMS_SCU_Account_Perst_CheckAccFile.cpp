#include "stdafx.h"

int Account_Perst_CheckAccFile()
{
	errno_t err;
	FILE *fp;
	if (err = fopen_s(&fp, "Account.dat", "rb") == 0) {
		fclose(fp);
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}
