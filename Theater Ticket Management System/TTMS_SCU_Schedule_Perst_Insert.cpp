#include "stdafx.h"
#include "TTMS_SCU_Schedule_Perst_Insert.h"

void Schedule_Perst_Insert(SCHEDULE * schedule)
{
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, "Schedule.dat", "ab+") != 0))
	{
		TTMS_GotoXY(55, 3);
		printf_s("File Code:%d error!", err);
		fclose(fp);
		exit(1);
	}
	else
	{
		fwrite(schedule, sizeof(SCHEDULE), 1, fp);
		fclose(fp);
	}
}
