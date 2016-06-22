#include "stdafx.h"
#include "TTMS_SCU_SaleData_UI_LookByP.h"

void SaleData_UI_LookByPage(int Arr[], int Page)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 11, 10);
	BIOS_GOTO_BOX(22, 100, 14, 13);
	BIOS_GOTO_BOX(22, 100, 17, 16);
	BIOS_GOTO_BOX(22, 100, 20, 19);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(33, 45, 5, 22);
	//	BIOS_GOTO_BOX(45, 45, 5, 22);
	BIOS_GOTO_BOX(60, 80, 5, 22);
	BIOS_GOTO_BOX(100, 100, 5, 22);
	TTMS_GotoXY(24, 6);
	printf_s("订单编号");
	TTMS_GotoXY(36, 6);
	printf_s("票务编号");
	TTMS_GotoXY(50, 6);
	printf_s("座位编号");
	TTMS_GotoXY(68, 6);
	printf_s("售票方式");
	TTMS_GotoXY(88, 6);
	printf_s("订单价格");
	TTMS_GotoXY(37, 24);
	printf_s("Left上一页  Right下一页  Esc返回上一层              PAGE:%d", Page);
	for (int i = ((Page - 1) * 5) + 1; i <= (Page) * 5; i++)
	{
		SALE *SaleData = SaleData_Perst_FetchByID(Arr[i - 1]);
		if (!SaleData)
		{
			break;
		}
		TICKET *ticket = Ticket_Perst_FetchByID(SaleData->data.ticket_id);
		TTMS_GotoXY(24, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", SaleData->data.id);
		TTMS_GotoXY(37, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", SaleData->data.ticket_id);
		TTMS_GotoXY(52, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", ticket->data.seat_id);
		TTMS_GotoXY(64, 9 + (i - 5 * (Page - 1) - 1) * 3);
		switch (SaleData->data.type)
		{
		case 1:printf_s("售票"); break;
		case -1:printf_s("退票"); break;
		default:
			break;
		}
		TTMS_GotoXY(90, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", SaleData->data.value);

	}
}
