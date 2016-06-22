#include "stdafx.h"
#include "TTMS_SCU_SaleData_Srv_FetchByID.h"

SALE * SaleData_Srv_FetchByID(int ID)
{

	return SaleData_Perst_FetchByID(ID);
}
