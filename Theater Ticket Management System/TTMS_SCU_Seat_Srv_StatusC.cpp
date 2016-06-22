#include "stdafx.h"
#include "TTMS_SCU_Seat_Srv_StatusC.h"

void Seat_Srv_StatusC(STUDIO *studio)
{
	for (int i = 1; i <= studio->data.rowsCount; i++)
	{
		for (int j = 1; j <= studio->data.colsCount; j++)
		{
			SEAT *seat;
			seat = (SEAT*)malloc(sizeof(SEAT));
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
