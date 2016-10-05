#include "stdafx.h"
#include "TTMS_SCU_SaleData_Perst_FetchByUser.h"

int SaleData_Perst_FentchByUser(char UserAccount[])
{
	FILE *fp;
	errno_t err;
	SALE *SaleData_temp;
	auto Count = 0;
	if (err = fopen_s(&fp, "Sale.dat", "rb") != 0)
	{
		return 0;
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0)
		{
			fclose(fp);
			return 0;
		}
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp))
		{
			SaleData_temp = static_cast<SALE *>(malloc(sizeof(SALE)));
			fread_s(SaleData_temp, sizeof(SALE), sizeof(SALE), 1, fp);
			if (strcmp(SaleData_temp->data.UserAcc,UserAccount) == 0)
			{
				fclose(fp);
				return SaleData_temp->data.id;
			}
		}
	}
	fclose(fp);
	return Count;
}
