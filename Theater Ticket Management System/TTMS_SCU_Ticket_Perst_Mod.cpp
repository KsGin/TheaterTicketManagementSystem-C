#include "stdafx.h"
#include "TTMS_SCU_Ticket_Perst_Mod.h"

int Ticket_Perst_ModStatus(TICKET *ticket)
{
	FILE *fp, *tempfp;
	TICKET *temp;
	fopen_s(&fp, "Ticket.dat", "rb");
	fopen_s(&tempfp, "Tickettemp.dat", "wb");
	temp = static_cast<TICKET*>(malloc(sizeof(TICKET)));
	while (!feof(fp))
	{
		fread_s(temp, sizeof(TICKET), sizeof(TICKET), 1, fp);
		if (ticket->data.id == temp->data.id)
		{
			fwrite(ticket, sizeof(TICKET), 1, tempfp);
		}
		else {
			fwrite(temp, sizeof(TICKET), 1, tempfp);
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Ticket.dat");
	rename("Tickettemp.dat", "Ticket.dat");
	return 0;
}
