#include "stdafx.h"
#include "TTMS_SCU_Ticket_Srv_StatusC.h"

void Ticket_StatusC(SCHEDULE *schedule)
{
	for (int i = 0; i < schedule->data.seat_count; i++)
	{
		TICKET *ticket;
		ticket = (TICKET*)malloc(sizeof(TICKET));
		ticket->data.schedule_id = schedule->data.id;
		PLAY *play = Play_Srv_FetchByID(schedule->data.play_id);
		ticket->data.price = play->data.price;
		ticket->data.status = TICKET_AVL;
		Ticket_Srv_Add(ticket);
	}
}
