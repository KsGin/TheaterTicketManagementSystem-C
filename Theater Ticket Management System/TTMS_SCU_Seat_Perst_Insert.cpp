#include "stdafx.h"
#include "TTMS_SCU_Seat_Perst_Insert.h"

void Seat_Perst_Insert(SEAT * seat)
{
	FILE *fp;
	errno_t err;
	if (err = fopen_s(&fp, "Seat.dat", "ab+") != 0)
	{
		TTMS_GotoXY(55, 3);
		printf_s("File Code:%d error!", err);
		fclose(fp);
		exit(1);
	}
	else
	{
		fwrite(seat, sizeof(SEAT), 1, fp);
		fclose(fp);
	}
}
