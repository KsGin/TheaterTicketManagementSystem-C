#include "stdafx.h"
#include "TTMS_SCU_Ticket_Perst_FetchByRC.h"

int Ticket_Perst_FetchBySS(int ScheduleID, int SeatID)
{
	FILE *fp;
	errno_t err;
	TICKET *ticket_temp;
	if (err = fopen_s(&fp, "Ticket.dat", "rb") != 0)
	{
		return 0;
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0)
		{
			fclose(fp);
			return 0;
		}
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp))
		{
			ticket_temp = (TICKET *)malloc(sizeof(TICKET));
			fread_s(ticket_temp, sizeof(TICKET), sizeof(TICKET), 1, fp);
			if (ticket_temp->data.schedule_id == ScheduleID && ticket_temp->data.seat_id == SeatID)
			{
			//	printf_s("%d  %d\n", ticket_temp->data.id, ticket_temp->data.seat_id);
				fclose(fp);
				return ticket_temp->data.id;
			}
		}
	}
	fclose(fp);
	return 0;
}
