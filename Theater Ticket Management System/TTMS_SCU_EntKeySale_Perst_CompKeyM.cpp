#include "stdafx.h"
#include "TTMS_SCU_EntKeySale_Perst_CompKeyM.h"

int EntKeySale_Perst_CompKeyM()
{
	FILE *fp;
	int key = EntKeySale_Perst_CompNewKeys();
	fopen_s(&fp, "EntityKeySale.dat", "w");
	fprintf_s(fp, "%d", key - 1);
	fclose(fp);
	return 0;
}
