#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_FetchAll.h"

void Account_Srv_FetchAll(USER * HEAD)
{
	FILE *USER_READ_FP;
	USER *NEW_NODE, *TEMP_NODE = HEAD;
	fopen_s(&USER_READ_FP, "Account.dat", "rb");
	while (feof(USER_READ_FP) != 0)
	{
		NEW_NODE = (USER *)malloc(sizeof(USER));
		fread_s(NEW_NODE, sizeof(USER), sizeof(USER), 1, USER_READ_FP);
		if (HEAD->NODE_NEXT = HEAD)
		{
			HEAD->NODE_PREV = NEW_NODE;
			HEAD->NODE_NEXT = NEW_NODE;
			NEW_NODE->NODE_PREV = HEAD;
			NEW_NODE->NODE_NEXT = HEAD;
			TEMP_NODE = NEW_NODE;
		}
		else
		{
			TEMP_NODE->NODE_NEXT = NEW_NODE;
			NEW_NODE->NODE_PREV = TEMP_NODE;
			NEW_NODE->NODE_NEXT = HEAD;
			TEMP_NODE = NEW_NODE;
		}
	}
	fclose(USER_READ_FP);
}
