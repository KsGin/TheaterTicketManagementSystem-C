#include "stdafx.h"
#include "TTMS_SCU_Schedule_Perst_Del.h"

int Schedule_Perst_DeleteByID(int ID)
{
	FILE *fp, *tempfp;
	SCHEDULE *schedule, *temp;
	auto flag = 0;
	schedule = Schedule_Srv_FetchByID(ID);
	if (schedule == nullptr)
	{
		return 0;
	}
	fopen_s(&fp, "Schedule.dat", "rb");
	fopen_s(&tempfp, "Scheduletemp.dat", "wb");
	temp = static_cast<SCHEDULE *>(malloc(sizeof(SCHEDULE)));
	fseek(fp, 0, SEEK_END);
	int sizefile = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp) && ftell(fp) < sizefile)
	{
		fread_s(temp, sizeof(SCHEDULE), sizeof(SCHEDULE), 1, fp);
		if (schedule->data.id != temp->data.id)
		{
			if (flag == 1)
			{
				temp->data.id = temp->data.id - 1;
			}
			fwrite(temp, sizeof(SCHEDULE), 1, tempfp);
		}
		else {
			flag = 1;
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Schedule.dat");
	rename("Scheduletemp.dat", "Schedule.dat");
	return 0;
}
