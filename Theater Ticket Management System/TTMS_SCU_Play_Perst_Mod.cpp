#include "stdafx.h"
#include "TTMS_SCU_Play_Perst_Mod.h"

int Play_Perst_Mod(PLAY * play)
{
	FILE *fp, *tempfp;
	PLAY *temp;
	fopen_s(&fp, "Play.dat", "rb");
	fopen_s(&tempfp, "Playtemp.dat", "wb");
	temp = (PLAY *)malloc(sizeof(PLAY));
	while (!feof(fp))
	{
		fread_s(temp, sizeof(PLAY), sizeof(PLAY), 1, fp);
		if (play->data.id == temp->data.id)
		{
			fwrite(play, sizeof(PLAY), 1, tempfp);
		}
		else {
			fwrite(temp, sizeof(PLAY), 1, tempfp);
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Play.dat");
	rename("Playtemp.dat", "Play.dat");
	return 0;
}
