#include "stdafx.h"
#include "CREAT_LIST_HEAD_USER.h"

USER* CREAT_LIST_HEAD_USER() {
	USER *HEAD;
	HEAD = (USER *)malloc(sizeof(USER));
	HEAD->NODE_NEXT = HEAD;
	HEAD->NODE_PREV = HEAD;
	strcpy_s(HEAD->USER_NAME, USER_LEN, "");
	strcpy_s(HEAD->USER_ACCOUT, USER_LEN, "");
	strcpy_s(HEAD->USER_PASSWORD, USER_LEN, "");
	HEAD->power = -1;
	return HEAD;
}

