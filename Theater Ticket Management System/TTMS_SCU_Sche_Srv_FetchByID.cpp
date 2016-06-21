#include "stdafx.h"
#include "TTMS_SCU_Sche_Srv_FetchByID.h"

SCHEDULE * Schedule_Srv_FetchByID(int ID)
{
	return Schedule_Perst_FetchByID(ID);
}
