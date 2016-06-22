#include "stdafx.h"
#include "TTMS_SCU_Ticket_Perst_FetchByID.h"

TICKET * Ticket_Perst_FetchByID(int ID)
{
	FILE *fp;
	errno_t err;
	TICKET *ticket_temp;
	if (err = fopen_s(&fp, "Ticket.dat", "rb") != 0)
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
			ticket_temp = (TICKET *)malloc(sizeof(TICKET));
			fread_s(ticket_temp, sizeof(TICKET), sizeof(TICKET), 1, fp);
			if (ticket_temp->data.id == ID)
			{
				fclose(fp);
				return ticket_temp;
			}
		}
	}
	fclose(fp);
	return nullptr;
}
