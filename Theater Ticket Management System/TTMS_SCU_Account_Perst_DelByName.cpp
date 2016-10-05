#include "stdafx.h"
#include "TTMS_SCU_Account_Perst_DelByName.h"

int Account_Perst_DelByName(char name[])
{
	FILE *fp, *tempfp;
	USER *temp;
	temp = static_cast<USER *>(malloc(sizeof(USER)));
	fopen_s(&fp, "Account.dat", "rb");
	fopen_s(&tempfp, "Accounttemp.dat", "wb");
	fseek(fp, 0, SEEK_END);
	int sizefile = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp) && ftell(fp) < sizefile )
	{
		fread(temp,  sizeof(USER), 1, fp);
		if (strcmp(name,temp->USER_NAME) != 0)
		{
			fwrite(temp, sizeof(USER), 1 , tempfp);
		}
	}
	free(temp);
	fclose(fp);
	fclose(tempfp);
	remove("Account.dat");
	rename("Accounttemp.dat", "Account.dat");
	return 1;
}
