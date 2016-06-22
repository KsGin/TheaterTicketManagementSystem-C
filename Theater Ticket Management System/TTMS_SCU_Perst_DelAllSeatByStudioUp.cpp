#include "stdafx.h"
#include "TTMS_SCU_Perst_DelAllSeatByStudioUp.h"

int Seat_Perst_DelByStudioID(int StudioID)
{
	FILE *fp, *tempfp;
	SEAT  *temp;
	fopen_s(&fp, "Seat.dat", "rb");
	fopen_s(&tempfp, "Seattemp.dat", "wb");
	temp = (SEAT *)malloc(sizeof(SEAT));
	fseek(fp, 0, SEEK_END);
	int sizefile = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp) && ftell(fp) < sizefile)
	{
		fread_s(temp, sizeof(SEAT), sizeof(SEAT), 1, fp);
		if (temp->data.RoomID != StudioID)
		{
			fwrite(temp, sizeof(SEAT), 1, tempfp);
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Seat.dat");
	rename("Seattemp.dat", "Seat.dat");
	return 0;
}
