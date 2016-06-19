#include "stdafx.h"
#include "TTMS_SCU_EntKey_Srv_CompNewKey.h"

int EntKey_Srv_CompNewKey()
{
	int key = EntKey_Perst_CompNewKeys();
	return key + 1;
}
