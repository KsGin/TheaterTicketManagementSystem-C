#include "stdafx.h"
#include "TTMS_SCU_EntKeyTicket_Perst_CompKeyM.h"

int EntKeyTicket_Perst_CompKeyM()
{
	FILE *fp;
	auto key = EntKeyTicket_Perst_CompNewKeys();
	fopen_s(&fp, "EntityKeyTicket.dat", "w");
	fprintf_s(fp, "%d", key - 1);
	fclose(fp);
	return 0;
}
