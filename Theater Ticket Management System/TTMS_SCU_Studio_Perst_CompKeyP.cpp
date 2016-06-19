#include "stdafx.h"
#include "TTMS_SCU_Studio_Perst_CompKeyP.h"

int EntKey_Perst_CompKeyP()
{
	FILE *fp;
	int key = EntKey_Srv_CompNewKey();
	fopen_s(&fp, "EnrityKey.dat", "w");
	fprintf_s(fp, "%d", key);
	fclose(fp);
	return 0;
}
