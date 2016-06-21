#include "stdafx.h"
#include "TTMS_SCU_EntKeySche_Perst_CompKeyM.h"

int EntKeySchedule_Perst_CompKeyM()
{
	FILE *fp;
	int key = EntKeySchedule_Perst_CompNewKeys();
	fopen_s(&fp, "EntityKeySchedule.dat", "w");
	fprintf_s(fp, "%d", key - 1);
	fclose(fp);
	return 0;
}
