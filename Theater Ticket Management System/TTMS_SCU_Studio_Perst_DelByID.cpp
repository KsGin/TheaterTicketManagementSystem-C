#include "stdafx.h"
#include "TTMS_SCU_Studio_Perst_DelByID.h"

int Studio_Perst_DeleteByID(int ID)
{
	FILE *fp, *tempfp;
	STUDIO *studio,*temp;
	studio = Studio_Perst_FetchByID(ID);
	if (studio == nullptr)
	{
		return 0;
	}
	fopen_s(&fp, "Studio.dat", "rb");
	fopen_s(&tempfp, "Studiotemp.dat", "wb");
	while (!feof(fp))
	{
		temp = (STUDIO *)malloc(sizeof(STUDIO));
		fread_s(temp, sizeof(STUDIO), sizeof(STUDIO), 1, fp);
		if (studio->data.id == temp->data.id)
		{
			continue;
		}
		fwrite(temp, sizeof(STUDIO), 1, tempfp);
	}
	fclose(fp);
	fclose(tempfp);
	remove("Studio.dat");
	rename("Studiotemp.dat", "Studio.dat");
	return 1;
}
