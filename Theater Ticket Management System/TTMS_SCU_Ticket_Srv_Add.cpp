#include "stdafx.h"
#include "TTMS_SCU_Ticket_Srv_Add.h"

int Ticket_Srv_Add(TICKET * ticket)
{
	ticket->data.id = EntKeyTicket_Perst_CompNewKeys();
	Ticket_Perst_Insert(ticket);
	EntKeyTicket_Perst_CompKeyP();
	return 0;
}
