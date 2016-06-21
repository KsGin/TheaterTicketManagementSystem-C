#include "stdafx.h"
#include "TTMS_SCU_Schedule_Srv_Check.h"

int Schedule_Srv_CheckReapt(SCHEDULE * schedule)
{
	int IDMax = EntKeySchedule_Perst_CompNewKeys();
	for (int i = 1; i <= IDMax; i++)
	{
		SCHEDULE *temp = Schedule_Srv_FetchByID(i);
		if (temp->data.play_id == schedule->data.play_id && temp->data.studio_id == schedule->data.studio_id && temp->time.daytime.year == schedule->time.daytime.year &&  temp->time.daytime.month == schedule->time.daytime.month && temp->time.daytime.day == schedule->time.daytime.day && temp->time.minute == schedule->time.minute && temp->time.hour == schedule->time.hour)
		{
			return 1;
		}
	}
	return 0;
}
