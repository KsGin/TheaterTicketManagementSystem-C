#include "stdafx.h"
#include "TTMS_SCU_Schedule_Srv_Add.h"

int Schedule_Srv_Add(SCHEDULE * schedule)
{
	if (Schedule_Srv_CheckReapt(schedule) == 1)
	{
		return 0;
	}
	else {
		schedule->data.id = EntKeySchedule_Perst_CompNewKeys() + 1;
		Schedule_Perst_Insert(schedule);
		EntKeySchedule_Perst_CompKeyP();
	}
	return 1;
}
