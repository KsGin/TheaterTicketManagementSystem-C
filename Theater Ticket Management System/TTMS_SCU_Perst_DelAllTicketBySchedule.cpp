#include "stdafx.h"
#include "TTMS_SCU_Perst_DelAllTicketBySchedule.h"

void TTMS_SCU_Perst_DelTicketByScheduleID(int ScheduleID)
{
	FILE *fp, *tempfp;
	TICKET  *temp;
	fopen_s(&fp, "Ticket.dat", "rb");
	fopen_s(&tempfp, "Tickettemp.dat", "wb");
	temp = (TICKET *)malloc(sizeof(TICKET));
	fseek(fp, 0, SEEK_END);
	int sizefile = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp) && ftell(fp) < sizefile)
	{
		fread_s(temp, sizeof(TICKET), sizeof(TICKET), 1, fp);
		if (temp->data.schedule_id != ScheduleID)
		{
			fwrite(temp, sizeof(TICKET), 1, tempfp);
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Ticket.dat");
	rename("Tickettemp.dat", "Ticket.dat");
}
