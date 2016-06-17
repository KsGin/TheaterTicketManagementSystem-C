#include "stdafx.h"
#include "TTMS_SCU_Account_Perst_CheckAccFile.h"

int Account_Perst_CheckAccFile(char useraccount[])
{
	FILE *fp;
	USER *TEMP;
	errno_t err;
	err = fopen_s(&fp, "Account.dat", "rb+");
	if (err != 0)
	{
		printf_s("´íÎó:·µ»Ø%d", err);
	}
	fseek(fp, 0, SEEK_SET);
	while (feof(fp) == 0)
	{
		TEMP = (USER *)malloc(sizeof(USER));
		fread(TEMP, sizeof(USER), 1, fp);
		if (strcmp(useraccount,TEMP->USER_ACCOUT) == 0)
		{
			fclose(fp);
			return 1;
		}
	} 
	fclose(fp);
	return 0;
}
