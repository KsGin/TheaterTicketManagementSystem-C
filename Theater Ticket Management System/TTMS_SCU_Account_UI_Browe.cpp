#include "stdafx.h"
#include "TTMS_SCU_Account_UI_Browe.h"

void Account_UI_Browe(USER *Admini)
{
	int NUMBER = 0;
	USER *HEAD,*PUT_TEMP;
	HEAD = Account_Srv_FetchAll();
	while (Account_UI_BoByPage(NUMBER*5, (NUMBER+1)*5, HEAD) == 0)
	{
		Sleep(2000);
		NUMBER++;
	}
	Account_Srv_Back(Admini);
}
