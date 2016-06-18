#include "stdafx.h"
#include "TTMS_SCU_Account_Srv_Add.h"

void Account_Srv_Add( char NAME[], char ACCOUT[], char PASSWORD[], int POWER, USER *HEAD) {
	USER *TEMP = HEAD;
	USER *USER_ADD;
	while (TEMP->NODE_NEXT != HEAD) {
		TEMP = TEMP->NODE_NEXT;
	}
	USER_ADD = (USER *)malloc(sizeof(USER));
	USER_ADD->power = POWER;
	strcpy_s(USER_ADD->USER_ACCOUT, USER_LEN, ACCOUT);
	strcpy_s(USER_ADD->USER_NAME, USER_LEN, NAME);
	strcpy_s(USER_ADD->USER_PASSWORD, USER_LEN, PASSWORD);
	TEMP->NODE_NEXT = USER_ADD;
	USER_ADD->NODE_PREV = TEMP;
	USER_ADD->NODE_NEXT = HEAD;
	HEAD->NODE_PREV = USER_ADD;
}