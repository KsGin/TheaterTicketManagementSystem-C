#include "stdafx.h"
#include "TTMS_SCU_Seat_Srv_Add.h"

int Seat_Srv_Add(SEAT * seat)
{
	if (Seat_Srv_CheckReapt(seat) == 1)
	{
		return 0;
	}
	else {
		seat->data.id = EntKeySeat_Perst_CompNewKeys() + 1;
		Seat_Perst_Insert(seat);
		EntKeySeat_Perst_CompKeyP();
	}
	return 1;
}
