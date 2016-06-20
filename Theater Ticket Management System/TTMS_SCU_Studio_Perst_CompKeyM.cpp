#include "stdafx.h"
#include "TTMS_SCU_Studio_Perst_CompKeyM.h"

int EntKey_Perst_CompKeyM()
{
	FILE *fp;
	int key = EntKey_Srv_CompNewKey();
	fopen_s(&fp, "EntityKey.dat", "w");
	fprintf_s(fp, "%d", key-2);
	fclose(fp);
	return 0;
}
