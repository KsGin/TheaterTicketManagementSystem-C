#include "stdafx.h"
#include "TTMS_SCU_Seat_Perst_Mod.h"

int Seat_Perst_Mod(SEAT * seat, int status)
{
	FILE *fp, *tempfp;
	SEAT *temp;
	fopen_s(&fp, "Seat.dat", "rb");
	fopen_s(&tempfp, "Seattemp.dat", "wb");
	temp = static_cast<SEAT *>(malloc(sizeof(SEAT)));
	while (!feof(fp))
	{
		fread_s(temp, sizeof(SEAT), sizeof(SEAT), 1, fp);
		if (seat->data.id == temp->data.id)
		{
			temp->data.status = static_cast<SEAT_STATUS>(status);
		}
		fwrite(temp, sizeof(SEAT), 1, tempfp);
	}
	fclose(fp);
	fclose(tempfp);
	remove("Seat.dat");
	rename("Seattemp.dat", "Seat.dat");
	return 0;
}
