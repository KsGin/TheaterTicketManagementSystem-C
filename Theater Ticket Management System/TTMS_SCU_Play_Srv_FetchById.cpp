#include "stdafx.h"
#include "TTMS_SCU_Play_Srv_FetchById.h"

PLAY * Play_Srv_FetchByID(int ID)
{
	return Play_Perst_FetchByID(ID);
}
