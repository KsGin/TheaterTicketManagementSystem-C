#include "stdafx.h"
#include "TTMS_SCU_EntKeySeat_Perst_CompKeyM.h"

int EntKeySeat_Perst_CompKeyM()
{
	FILE *fp;
	int key = EntKeySeat_Perst_CompNewKeys();
	fopen_s(&fp, "EntityKeySeat.dat", "w");
	fprintf_s(fp, "%d", key - 1);
	fclose(fp);
	return 0;
}
