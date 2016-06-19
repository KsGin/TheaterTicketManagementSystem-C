#include "stdafx.h"
#include "TTMS_SCU_Studio_Perst_Insert.h"

void Studio_Perst_Insert(STUDIO * studio)
{
	FILE *fp;
	errno_t err;
	if (err = fopen_s(&fp, "Studio.dat", "ab+") != 0)
	{
		TTMS_GotoXY(55, 3);
		printf_s("File Code:%d error!", err);
		fclose(fp);
		exit(1);
	}
	else
	{
		fwrite(studio, sizeof(STUDIO), 1, fp);
		fclose(fp);
	}
}
