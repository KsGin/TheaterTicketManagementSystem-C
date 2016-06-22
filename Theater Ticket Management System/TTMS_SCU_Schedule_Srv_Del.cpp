#include "stdafx.h"
#include "TTMS_SCU_Schedule_Srv_Del.h"

int Schedule_Srv_Delete(int ID)
{
	Schedule_Perst_DeleteByID(ID);
	EntKeySchedule_Perst_CompKeyM();
	return 0;
}
