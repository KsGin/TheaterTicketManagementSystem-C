#include "stdafx.h"
#include "TTMS_SCU_Seat_Perst_FetchByID.h"

SEAT * Seat_Perst_FetchByID(int ID)
{
	FILE *fp;
	errno_t err;
	SEAT *seat_temp;
	if (err = fopen_s(&fp, "Seat.dat", "rb") != 0)
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
			seat_temp = (SEAT *)malloc(sizeof(SEAT));
			fread_s(seat_temp, sizeof(SEAT), sizeof(SEAT), 1, fp);
			if (seat_temp->data.id == ID)
			{
				fclose(fp);
				return seat_temp;
			}
		}
	}
	fclose(fp);
	return nullptr;
}
