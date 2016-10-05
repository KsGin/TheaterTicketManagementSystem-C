#include "stdafx.h"
#include "TTMS_SCU_Ticket_Srv_StatusC.h"

void Ticket_StatusC(SCHEDULE *schedule)
{
	for (auto i = 0; i < schedule->data.seat_count; i++)
	{
		TICKET *ticket;
		ticket = static_cast<TICKET*>(malloc(sizeof(TICKET)));
		ticket->data.schedule_id = schedule->data.id;
		auto play = Play_Srv_FetchByID(schedule->data.play_id);
		ticket->data.price = play->data.price;
		ticket->data.status = TICKET_AVL;
		ticket->data.seat_id = i + 1;
		Ticket_Srv_Add(ticket);
	}
}
