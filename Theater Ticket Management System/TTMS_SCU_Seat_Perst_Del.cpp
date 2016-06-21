#include "stdafx.h"
#include "TTMS_SCU_Seat_Perst_Del.h"

int Seat_Perst_DeleteByID(int ID)
{
	FILE *fp, *tempfp;
	SEAT *seat, *temp;
	int flag = 0;
	seat = Seat_Perst_FetchByID(ID);
	if (seat == nullptr)
	{
		return 0;
	}
	fopen_s(&fp, "Seat.dat", "rb");
	fopen_s(&tempfp, "Seattemp.dat", "wb");
	temp = (SEAT *)malloc(sizeof(SEAT));
	fseek(fp, 0, SEEK_END);
	int sizefile = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp) && ftell(fp) < sizefile)
	{
		fread_s(temp, sizeof(SEAT), sizeof(SEAT), 1, fp);
		if (seat->data.id != temp->data.id)
		{
			if (flag == 1)
			{
				temp->data.id = temp->data.id - 1;
			}
			fwrite(temp, sizeof(SEAT), 1, tempfp);
		}
		else {
			flag = 1;
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Seat.dat");
	rename("Seattemp.dat", "Seat.dat");
	return 1;
}
