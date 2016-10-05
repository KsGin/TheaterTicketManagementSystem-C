#include "stdafx.h"
#include "TTMS_SCU_EntKeyPlay_Perst_CompKeyM.h"

int EntKeyPlay_Perst_CompKeyM()
{
	FILE *fp;
	auto key = EntKeyPlay_Perst_CompNewKeys();
	fopen_s(&fp, "EntityKeyPlay.dat", "w");
	fprintf_s(fp, "%d", key - 1);
	fclose(fp);
	return 0;
}
