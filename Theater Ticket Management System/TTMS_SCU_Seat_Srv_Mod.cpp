#include "stdafx.h"
#include "TTMS_SCU_Seat_Srv_Mod.h"

int Seat_Srv_Mod(SEAT *seat,int status)
{
	if (Seat_Perst_Mod(seat,status))
	{
		return 1;
	}
	return 0;
}
