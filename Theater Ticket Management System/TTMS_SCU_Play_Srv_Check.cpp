#include "stdafx.h"
#include "TTMS_SCU_Play_Srv_Check.h"

int Play_Srv_CheckReapt(PLAY * play)
{
	auto IDMax = EntKeyPlay_Perst_CompNewKeys();
	for (auto i = 1; i <= IDMax; i++)
	{
		auto temp = Play_Perst_FetchByID(i);
		if (strcmp(temp->data.area, play->data.area) == 0 && strcmp(temp->data.name, play->data.name) == 0 && temp->data.duration ==  play->data.duration)
		{
			return 1;
		}
	}
	return 0;
}
