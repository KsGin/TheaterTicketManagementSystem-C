#include "stdafx.h"
#include "TTMS_SCU_Sale_Perst_Insert.h"

int Sale_Perst_Insert(SALE * sale)
{
	FILE *fp;
	errno_t err;
	if (err = fopen_s(&fp, "Sale.dat", "ab+") != 0)
	{
		TTMS_GotoXY(55, 3);
		printf_s("File Code:%d error!", err);
		fclose(fp);
		exit(1);
	}
	else
	{
		fwrite(sale, sizeof(SALE), 1, fp);
		fclose(fp);
	}
	return 0;
}
