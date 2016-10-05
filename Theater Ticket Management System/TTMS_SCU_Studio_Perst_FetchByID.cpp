#include "stdafx.h"
#include "TTMS_SCU_Studio_Perst_FetchByID.h"

STUDIO * Studio_Perst_FetchByID(int ID)
{
	FILE *fp;
	errno_t err;
	STUDIO *studio_temp;
	if ((err = fopen_s(&fp,"Studio.dat","rb") != 0))
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
			studio_temp = static_cast<STUDIO *>(malloc(sizeof(STUDIO)));
			fread_s(studio_temp, sizeof(STUDIO), sizeof(STUDIO), 1, fp);
			if (studio_temp->data.id == ID)
			{
				fclose(fp);
				return studio_temp;
			}
		}
	}
	fclose(fp);
	return nullptr;
}
