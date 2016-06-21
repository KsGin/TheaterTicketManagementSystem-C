#include "stdafx.h"
#include "TTMS_SCU_Play_Srv_Mod.h"

int Play_Srv_Mod(PLAY * play)
{
	if (Play_Perst_Mod(play))
	{
		return 1;
	}
	return 0;
}
