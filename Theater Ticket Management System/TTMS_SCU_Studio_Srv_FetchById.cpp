#include "stdafx.h"
#include "TTMS_SCU_Studio_Srv_FetchById.h"

STUDIO * Studio_Srv_FetchByID(int ID)
{
	return Studio_Perst_FetchByID(ID);
}
