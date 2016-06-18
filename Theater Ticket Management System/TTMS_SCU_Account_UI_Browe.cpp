#include "stdafx.h"
#include "TTMS_SCU_Account_UI_Browe.h"

void Account_UI_Browe(USER *Admini)
{
	int NUMBER = 0;
	USER *HEAD;
	HEAD = Account_Srv_FetchAll();
	while (Account_UI_BoByPage(NUMBER*5, (NUMBER+1)*5, HEAD) == 0)
	{
		NUMBER++;
	}
	int max = NUMBER;
	NUMBER = 0;
	char key[10];
	Account_UI_BoByPage(NUMBER * 5, (NUMBER + 1) * 5, HEAD);
	strcpy_s(key, 10, GET_KEY());
	while (strcmp(key,"Esc") != 0)
	{
		if (strcmp(key,"Left") == 0 && NUMBER > 0)
		{
			NUMBER--;
			Account_UI_BoByPage(NUMBER * 5, (NUMBER + 1) * 5, HEAD);
		}
		else if (strcmp(key, "Right") == 0 && NUMBER < max)
		{
			NUMBER++;
			Account_UI_BoByPage(NUMBER * 5, (NUMBER + 1) * 5, HEAD);
		}
		strcpy_s(key, 10, GET_KEY());
	}
	Account_UI_MgtEntry(Admini);
}
