#include "stdafx.h"
#include "TTMS_SCU_Play_Perst_Del.h"

int Play_Perst_DeleteByID(int ID)
{
	FILE *fp, *tempfp;
	PLAY *play, *temp;
	int flag = 0;
	play = Play_Srv_FetchByID(ID);
	if (play == nullptr)
	{
		return 0;
	}
	fopen_s(&fp, "Play.dat", "rb");
	fopen_s(&tempfp, "Playtemp.dat", "wb");
	temp = (PLAY *)malloc(sizeof(PLAY));
	fseek(fp, 0, SEEK_END);
	int sizefile = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp) && ftell(fp) < sizefile)
	{
		fread_s(temp, sizeof(PLAY), sizeof(PLAY), 1, fp);
		if (play->data.id != temp->data.id)
		{
			if (flag == 1)
			{
				temp->data.id = temp->data.id - 1;
			}
			fwrite(temp, sizeof(PLAY), 1, tempfp);
		}
		else {
			flag = 1;
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Play.dat");
	rename("Playtemp.dat", "Play.dat");
	return 0;
}
