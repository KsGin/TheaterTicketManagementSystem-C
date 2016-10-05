#include "stdafx.h"
#include "TTMS_SCU_Studio_Perst_CompKeyP.h"

int EntKey_Perst_CompKeyP()
{
	FILE *fp;
	auto key = EntKey_Srv_CompNewKey();
	fopen_s(&fp, "EntityKey.dat", "w");
	fprintf_s(fp, "%d", key);
	fclose(fp);
	return 0;
}
