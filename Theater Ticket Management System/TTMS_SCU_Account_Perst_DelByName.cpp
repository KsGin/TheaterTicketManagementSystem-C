#include "stdafx.h"
#include "TTMS_SCU_Account_Perst_DelByName.h"

int Account_Perst_DelByName(char name[])
{
	FILE *fp, *tempfp;
	USER *temp;
	fopen_s(&fp, "Account.dat", "rb");
	fopen_s(&tempfp, "Accounttemp.dat", "wb");
	while (!feof(fp))
	{
		temp = (USER *)malloc(sizeof(USER));
		fread_s(temp, sizeof(USER), sizeof(USER), 1, fp);
		if (strcmp(name,temp->USER_ACCOUT) == 0)
		{
			continue;
		}
		fwrite(temp, sizeof(USER), 1, tempfp);
	}
	fclose(fp);
	fclose(tempfp);
	remove("Account.dat");
	rename("Accounttemp.dat", "Account.dat");
	return 1;
}
