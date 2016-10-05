#include "stdafx.h"
#include "TTMS_SCU_Seat_Srv_Check.h"

int Seat_Srv_CheckReapt(SEAT * seat)
{
	auto IDMax = EntKeySeat_Perst_CompNewKeys();
	for (auto i = 1; i <= IDMax; i++)
	{
		auto *temp = Seat_Srv_FetchByID(i);
		if (temp && temp->data.RoomID == seat->data.RoomID && temp->data.row == seat->data.row && seat->data.col == temp->data.col)
		{
			return 1;
		}
	}
	return 0;
}
