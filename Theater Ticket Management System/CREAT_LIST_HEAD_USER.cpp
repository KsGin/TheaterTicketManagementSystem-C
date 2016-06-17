#include "stdafx.h"
#include "CREAT_LIST_HEAD_USER.h"

void CREAT_LIST_HEAD_USER(USER *HEAD) {
	HEAD->NODE_NEXT = HEAD;
	HEAD->NODE_PREV = HEAD;
	HEAD->ID = 0;
	strcpy_s(HEAD->USER_NAME, USER_LEN, "");
	strcpy_s(HEAD->USER_PASSWORD, USER_LEN, "");
	HEAD->power = 0;
}

