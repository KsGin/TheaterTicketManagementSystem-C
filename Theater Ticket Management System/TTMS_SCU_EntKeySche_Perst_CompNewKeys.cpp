#include "stdafx.h"
#include "TTMS_SCU_EntKeySche_Perst_CompNewKeys.h"

int EntKeySchedule_Perst_CompNewKeys()
{
	FILE *fp;
	int key;
	errno_t err;
	if ((err = fopen_s(&fp, "EntityKeySchedule.dat", "r") == 0)) {
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0)
		{
			fprintf_s(fp, "%d", 0);
			fclose(fp);
			return 0;
		}
		fseek(fp, 0, SEEK_SET);
		fscanf_s(fp, "%d", &key);
		fclose(fp);
		return key;
	}
	else {
		fopen_s(&fp, "EntityKeySchedule.dat", "w");
		fprintf_s(fp, "%d", 0);
		fclose(fp);
		return 0;
	}
	return 0;
}
