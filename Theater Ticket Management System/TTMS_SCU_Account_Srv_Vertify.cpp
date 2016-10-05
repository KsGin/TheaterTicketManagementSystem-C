#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_Vertify.h"

int Account_Srv_Verify(char ACCOUNT[], char PASSWORD[])
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
		if (strcmp(ACCOUNT, TEMP->USER_ACCOUT) == 0)
		{
			if (strcmp(PASSWORD,TEMP->USER_PASSWORD) == 0)
			{
				fclose(fp);
				return 1;
			}
			else {
				fclose(fp);
				return 0;
			}
		}
	}
	fclose(fp);
	return 0;
}
