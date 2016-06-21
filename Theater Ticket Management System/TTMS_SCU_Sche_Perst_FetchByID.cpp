#include "stdafx.h"
#include "TTMS_SCU_Sche_Perst_FetchByID.h"

SCHEDULE * Schedule_Perst_FetchByID(int ID)
{
	FILE *fp;
	errno_t err;
	SCHEDULE *Schedule_temp;
	if (err = fopen_s(&fp, "Schedule.dat", "rb") != 0)
	{
		return nullptr;
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0)
		{
			fclose(fp);
			return nullptr;
		}
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp))
		{
			Schedule_temp = (SCHEDULE *)malloc(sizeof(SCHEDULE));
			fread_s(Schedule_temp, sizeof(SCHEDULE), sizeof(SCHEDULE), 1, fp);
			if (Schedule_temp->data.id == ID)
			{
				fclose(fp);
				return Schedule_temp;
			}
		}
	}
	fclose(fp);
	return nullptr;
}
