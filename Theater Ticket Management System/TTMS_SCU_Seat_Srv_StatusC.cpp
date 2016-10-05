#include "stdafx.h"
#include "TTMS_SCU_Seat_Srv_StatusC.h"

void Seat_Srv_StatusC(STUDIO *studio)
{
	for (auto i = 1; i <= studio->data.rowsCount; i++)
	{
		for (auto j = 1; j <= studio->data.colsCount; j++)
		{
			SEAT *seat;
			seat = static_cast<SEAT*>(malloc(sizeof(SEAT)));
			seat->data.row = i;
			seat->data.col = j;
			seat->data.RoomID = studio->data.id;
			seat->data.status = SEAT_GOOD;
			seat->data.id = EntKeySeat_Perst_CompNewKeys() + 1;
			Seat_Perst_Insert(seat);
			EntKeySeat_Perst_CompKeyP();
		}
	}
}
