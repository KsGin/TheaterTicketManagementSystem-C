#include "stdafx.h"
#include "TTMS_SCU_Account_perst_Update.h"

int Account_Perst_Update(USER * Head)
{
	USER *User = Head;
	FILE *fp;
	int count = 0;
	fopen_s(&fp, "Account.dat", "wb+");
	fseek(fp, 0, SEEK_SET);
	while (User != Head)
	{
		count++;
		fwrite(User, sizeof(USER), 1, fp);
		User = User->NODE_NEXT;
	}
	fclose(fp);
	return 0;
}
