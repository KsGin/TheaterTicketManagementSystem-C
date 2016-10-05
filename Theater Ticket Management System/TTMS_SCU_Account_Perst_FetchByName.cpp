#include "stdafx.h"
#include "TTMS_SCU_Account_Perst_FetchByName.h"

USER * Account_Perst_FetchByName(char username[])
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
		TEMP = static_cast<USER *>(malloc(sizeof(USER)));
		fread(TEMP, sizeof(USER), 1, fp);
		if (strcmp(username, TEMP->USER_NAME) == 0)
		{
			fclose(fp);
			return TEMP;
		}
	}
	fclose(fp);
	return nullptr;
}
