#include "stdafx.h"
#include "TTMS_SCU_Srv_DelAllSeatByStudioUp.h"

void Seat_Srv_DelAll(STUDIO * studio)
{
	if (studio->data.id)
	{
		Seat_Perst_DelByStudioID(studio->data.id);
	}
}
