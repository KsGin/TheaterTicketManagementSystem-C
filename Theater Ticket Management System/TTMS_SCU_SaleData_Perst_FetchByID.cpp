#include "stdafx.h"
#include "TTMS_SCU_SaleData_Perst_FetchByID.h"

SALE * SaleData_Perst_FetchByID(int ID)
{
	FILE *fp;
	errno_t err;
	SALE *SaleData_temp;
	if (err = fopen_s(&fp, "Sale.dat", "rb") != 0)
	{
		return nullptr;
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0)
		{
			fclose(fp);
			return nullptr;
		}
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp))
		{
			SaleData_temp = (SALE *)malloc(sizeof(SALE));
			fread_s(SaleData_temp, sizeof(SALE), sizeof(SALE), 1, fp);
			if (SaleData_temp->data.id == ID)
			{
				fclose(fp);
				return SaleData_temp;
			}
		}
	}
	fclose(fp);
	return nullptr;
}
