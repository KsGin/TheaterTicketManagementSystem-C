#include "stdafx.h"
#include "TTMS_SCU_EntKeySche_Perst_CompKeyP.h"

int EntKeySchedule_Perst_CompKeyP()
{
	FILE *fp;
	auto key = EntKeySchedule_Perst_CompNewKeys();
	fopen_s(&fp, "EntityKeySchedule.dat", "w");
	fprintf_s(fp, "%d", key + 1);
	fclose(fp);
	return 0;
}
