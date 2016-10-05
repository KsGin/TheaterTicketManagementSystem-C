#include "stdafx.h"
#include "TTMS_SCU_Account_Perst_ModP.h"

int Account_Perst_ModPassword(USER *Mod_user, char NewPassword[])
{
	FILE *fp, *tempfp;
	USER *temp;
	fopen_s(&fp, "Account.dat", "rb");
	fopen_s(&tempfp, "Accounttemp.dat", "wb");
	temp = static_cast<USER *>(malloc(sizeof(USER)));
	fseek(fp, 0, SEEK_END);
	int sizefile = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp) && ftell(fp) < sizefile)
	{
		fread_s(temp, sizeof(USER), sizeof(USER), 1, fp);
		if (strcmp(Mod_user->USER_ACCOUT,temp->USER_ACCOUT) == 0)
		{
			strcpy_s(temp->USER_PASSWORD,NewPassword);
		}
		fwrite(temp, sizeof(USER), 1, tempfp);
	}
	fclose(fp);
	fclose(tempfp);
	remove("Account.dat");
	rename("Accounttemp.dat", "Account.dat");
	return 1;
}
