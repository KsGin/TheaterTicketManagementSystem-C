#include "stdafx.h"
#include "TTMS_SCU_Schedule_Perst_Mod.h"

int Schedule_Perst_Mod(SCHEDULE * schedule)
{
	FILE *fp, *tempfp;
	SCHEDULE *temp;
	fopen_s(&fp, "Schedule.dat", "rb");
	fopen_s(&tempfp, "Scheduletemp.dat", "wb");
	temp = (SCHEDULE *)malloc(sizeof(SCHEDULE));
	while (!feof(fp))
	{
		fread_s(temp, sizeof(SCHEDULE), sizeof(SCHEDULE), 1, fp);
		if (schedule->data.id == temp->data.id)
		{
			fwrite(schedule, sizeof(SCHEDULE), 1, tempfp);
		}
		else {
			fwrite(temp, sizeof(SCHEDULE), 1, tempfp);
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Schedule.dat");
	rename("Scheduletemp.dat", "Schedule.dat");
	return 0;
}
