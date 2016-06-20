#include "stdafx.h"
#include "TTMS_SCU_Account_Perst_ModP.h"

int Account_Perst_ModPassword(USER *Mod_user, char NewPassword[])
{
	FILE *fp;
	errno_t err;
	USER *user;
	if (err = fopen_s(&fp,"Account.dat","rb+") != 0)
	{
		return err;
	}
	else
	{
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp))
		{
			int Count = 0;
			user = (USER *)malloc(sizeof(USER));
			fread_s(user, sizeof(USER), sizeof(USER), 1, fp);
			if (strcmp(Mod_user->USER_ACCOUT , user->USER_ACCOUT) == 0) {
				strcpy_s(user->USER_PASSWORD,USER_LEN,NewPassword);
				fseek(fp, Count*sizeof(USER), SEEK_SET);
				fwrite(user, sizeof(USER), 1, fp);
				fclose(fp);
				return 1;
			}
			Count++;
		}
	}
	fclose(fp);
	return 0;
}
