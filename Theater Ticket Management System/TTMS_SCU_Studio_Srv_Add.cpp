#include "stdafx.h"
#include "TTMS_SCU_Studio_Srv_Add.h"

void Studio_Srv_Add(STUDIO * studio)
{
	studio->data.id = EntKey_Srv_CompNewKey();
	studio->next = nullptr;
	studio->prev = nullptr;
	Studio_Perst_Insert(studio);
	EntKey_Perst_CompKeyP();
	Seat_Srv_StatusC(studio);
}
