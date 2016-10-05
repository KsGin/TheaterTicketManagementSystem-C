#include "stdafx.h"
#include "TTMS_SCU_Studio_Perst_Mod.h"

void Studio_Perst_Mod(STUDIO * studio)
{
	FILE *fp, *tempfp;
	STUDIO *temp;
	fopen_s(&fp, "Studio.dat", "rb");
	fopen_s(&tempfp, "Studiotemp.dat", "wb");
	temp = static_cast<STUDIO *>(malloc(sizeof(STUDIO)));
	while (!feof(fp))
	{
		fread_s(temp, sizeof(STUDIO), sizeof(STUDIO), 1, fp);
		if (studio->data.id == temp->data.id)
		{
			memcpy(temp,studio,sizeof(STUDIO));
		}
		fwrite(temp, sizeof(STUDIO), 1, tempfp);
	}
	fclose(fp);
	fclose(tempfp);
	remove("Studio.dat");
	rename("Studiotemp.dat", "Studio.dat");
}
