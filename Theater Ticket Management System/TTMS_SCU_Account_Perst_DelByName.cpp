#include "stdafx.h"
#include "TTMS_SCU_Account_Perst_DelByName.h"

int Account_Perst_DelByName(char name[])
{
	FILE *fp, *tempfp;
	USER *temp;
	int flag = 0;
	fopen_s(&fp, "Account.dat", "rb");
	fopen_s(&tempfp, "Accounttemp.dat", "wb");
	while (!feof(fp) && flag == 0)
	{
		flag = 0;
		temp = (USER *)malloc(sizeof(USER));
		fread_s(temp, sizeof(USER), sizeof(USER), 1, fp);
		if (strcmp(name,temp->USER_ACCOUT) == 0)
		{
			flag = 1;
		}
		if (flag == 0)
		{
			fwrite(temp, sizeof(USER), 1, tempfp);
		}
		
	}
	fclose(fp);
	fclose(tempfp);
	remove("Account.dat");
	rename("Accounttemp.dat", "Account.dat");
	return 1;
}
