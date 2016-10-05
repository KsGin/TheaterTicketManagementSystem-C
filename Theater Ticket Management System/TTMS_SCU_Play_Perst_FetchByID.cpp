#include "stdafx.h"
#include "TTMS_SCU_Play_Perst_FetchByID.h"

PLAY * Play_Perst_FetchByID(int ID)
{
	FILE *fp;
	errno_t err;
	PLAY *play_temp;
	if ((err = fopen_s(&fp, "Play.dat", "rb") != 0))
	{
		return nullptr;
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0)
		{
			fclose(fp);
			return nullptr;
		}
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp))
		{
			play_temp = static_cast<PLAY *>(malloc(sizeof(PLAY)));
			fread_s(play_temp, sizeof(PLAY), sizeof(PLAY), 1, fp);
			if (play_temp->data.id == ID)
			{
				fclose(fp);
				return play_temp;
			}
		}
	}
	fclose(fp);
	return nullptr;
}
