#include "stdafx.h"
#include "TTMS_SCU_SaleData_UI_Browe.h"

void SaleData_UI_Browe(USER * user, int arr[], int indexMax)
{
	auto p = 1;
	system("cls");
	SaleData_UI_LookByPage(arr, p);
	auto KeyMaX = indexMax;
	char k[15];
	strcpy_s(k, 15, GET_KEY());
	while (strcmp(k, "Esc") != 0)
	{
		if (strcmp(k, "Right") == 0 && p <= KeyMaX / 5)
		{
			SaleData_UI_LookByPage(arr, ++p);
		}
		if (strcmp(k, "Left") == 0 && p > 1)
		{
			SaleData_UI_LookByPage(arr, --p);
		}
		strcpy_s(k, 15, GET_KEY());
	}
	Main_UI_MgtEntry(user);
}
