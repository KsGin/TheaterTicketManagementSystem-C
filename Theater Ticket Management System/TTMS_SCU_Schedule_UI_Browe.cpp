#include "stdafx.h"
#include "TTMS_SCU_Schedule_UI_Browe.h"

void Schedule_UI_Browe(USER * user)
{
	int p = 1;
	system("cls");
	int KeyMaX = EntKeySchedule_Perst_CompNewKeys() - 1;
	Schedule_UI_LookByPage(p);
	char k[15];
	strcpy_s(k, 15, GET_KEY());
	while (strcmp(k, "Esc") != 0)
	{
		if (strcmp(k, "Right") == 0 && p <= KeyMaX / 5)
		{
			Schedule_UI_LookByPage(++p);
		}
		if (strcmp(k, "Left") == 0 && p > 1)
		{
			Schedule_UI_LookByPage(--p);
		}
		strcpy_s(k, 15, GET_KEY());
	}
	Schedule_UI_MgtEntry(user);
}
