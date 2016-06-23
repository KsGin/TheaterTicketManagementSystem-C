#include "stdafx.h"
#include "TTMS_SCU_Schedule_Srv_Mod.h"

int Schedule_Srv_Mod(SCHEDULE * schedule)
{
	TTMS_SCU_Perst_DelTicketByScheduleID(schedule->data.id);
	Ticket_StatusC(schedule);
	if (Schedule_Perst_Mod(schedule))
	{
		return 1;
	}
	return 0;
}
