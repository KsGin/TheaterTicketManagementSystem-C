#include "stdafx.h"
#include "TTMS_SCU_Seat_Srv_FetchByID.h"

SEAT * Seat_Srv_FetchByID(int ID)
{
	return Seat_Perst_FetchByID(ID);
}
