#include "stdafx.h"
#include "TTMS_SCU_EntKeySale_Perst_CompKeyP.h"

int EntKeySale_Perst_CompKeyP()
{
	FILE *fp;
	int key = EntKeySale_Perst_CompNewKeys();
	fopen_s(&fp, "EntityKeySale.dat", "w");
	fprintf_s(fp, "%d", key + 1);
	fclose(fp);
	return 0;
}
