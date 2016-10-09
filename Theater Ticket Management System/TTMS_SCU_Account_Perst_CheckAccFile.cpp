#include "stdafx.h"
#include <memory>

int Account_Perst_CheckAccFile()
{
	errno_t err;
	
	FILE *fp;
	if ((err = fopen_s(&fp, "Account.dat", "rb") == 0)) {
		fseek(fp, 0, SEEK_END);
		int len = ftell(fp);
		fclose(fp);
		if (len == 0)
		{
			return 0;
		}
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}
