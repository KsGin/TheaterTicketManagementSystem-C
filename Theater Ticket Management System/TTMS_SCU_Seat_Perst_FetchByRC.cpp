#include "stdafx.h"
#include "TTMS_SCU_Seat_Perst_FetchByRC.h"

int Seat_Perst_FetchByRC(int Row, int Col, int studioID)
{
	FILE *fp;
	errno_t err;
	SEAT *seat_temp;
	if (err = fopen_s(&fp, "Seat.dat", "rb") != 0)
	{
		return 0;
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0)
		{
			fclose(fp);
			return 0;
		}
		fseek(fp, 0, SEEK_SET);
		while (!feof(fp))
		{
			seat_temp = (SEAT *)malloc(sizeof(SEAT));
			fread_s(seat_temp, sizeof(SEAT), sizeof(SEAT), 1, fp);
			if (seat_temp->data.col == Col && seat_temp->data.row == Row && seat_temp->data.RoomID == studioID);
			{
				fclose(fp);
				return seat_temp->data.id;
			}
		}
	}
	fclose(fp);
	return 0;
}
