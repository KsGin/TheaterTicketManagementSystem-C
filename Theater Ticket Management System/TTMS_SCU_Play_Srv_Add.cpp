#include "stdafx.h"
#include "TTMS_SCU_Play_Srv_Add.h"

int Play_Srv_Add(PLAY * play)
{
	if (Play_Srv_CheckReapt(play) == 1)
	{
		return 0;
	}
	else {
		play->data.id = EntKeyPlay_Perst_CompNewKeys() + 1;
		Play_Perst_Insert(play);
		EntKeyPlay_Perst_CompKeyP();
	}
	return 1;
}
