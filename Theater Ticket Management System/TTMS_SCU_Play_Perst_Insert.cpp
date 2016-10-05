#include "stdafx.h"
#include "TTMS_SCU_Play_Perst_Insert.h"

void Play_Perst_Insert(PLAY * play)
{
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, "Play.dat", "ab+") != 0))
	{
		TTMS_GotoXY(55, 3);
		printf_s("File Code:%d error!", err);
		fclose(fp);
		exit(1);
	}
	else
	{
		fwrite(play, sizeof(PLAY), 1, fp);
		fclose(fp);
	}
}
