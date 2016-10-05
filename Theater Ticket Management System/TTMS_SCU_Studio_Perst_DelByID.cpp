#include "stdafx.h"
#include "TTMS_SCU_Studio_Perst_DelByID.h"

int Studio_Perst_DeleteByID(int ID)
{
	FILE *fp, *tempfp;
	STUDIO *studio,*temp;
	auto flag = 0;
	studio = Studio_Perst_FetchByID(ID);
	if (studio == nullptr)
	{
		return 0;
	}
	fopen_s(&fp, "Studio.dat", "rb");
	fopen_s(&tempfp, "Studiotemp.dat", "wb");
	temp = static_cast<STUDIO *>(malloc(sizeof(STUDIO)));
	fseek(fp, 0, SEEK_END);
	int sizefile = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp) && ftell(fp) < sizefile)
	{
		fread_s(temp, sizeof(STUDIO), sizeof(STUDIO), 1, fp);
		if (studio->data.id != temp->data.id)
		{
			if (flag == 1)
			{
				temp->data.id = temp->data.id - 1;
			}
			fwrite(temp, sizeof(STUDIO), 1, tempfp);
		}
		else {
			flag = 1;
		}
	}
	fclose(fp);
	fclose(tempfp);
	remove("Studio.dat");
	rename("Studiotemp.dat", "Studio.dat");
	return 1;
}
