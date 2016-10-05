#include "stdafx.h"
#include "TTMS_SCU_SaleData_UI_Analysis.h"
#define INDEX_MAX 1000
void SaleData_UI_Analysis(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("请输入售票员姓名:");
	char UserName[15];
	scanf_s("%s", UserName,15);
	auto *Sale_User = Account_Perst_FetchByName(UserName);
	if (!Sale_User || Sale_User->power != 2)
	{
		TTMS_GotoXY(55, 15);
		printf_s("没有此售票员");
		_getch();
		Main_UI_MgtEntry(user);
	}
	TTMS_GotoXY(52, 6);
	printf_s("  售票员%s            ", Sale_User->USER_NAME);
	auto CountMax = EntKeySale_Perst_CompNewKeys();
	int SaleData[INDEX_MAX],Count = 0;
	for (auto i = 0; i <= CountMax; i++)
	{
		auto *sale = SaleData_Srv_FetchByID(i);
		if (sale && !strcmp(sale->data.UserAcc,Sale_User->USER_ACCOUT))
		{
			SaleData[Count] = sale->data.id;
			++Count;
			TTMS_GotoXY(50, 13);
			printf_s("已查找到%d个销售记录", Count);
			Sleep(500);
		}
	}
	SaleData_UI_Browe(user, SaleData, Count);
}
