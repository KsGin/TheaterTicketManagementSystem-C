#include "stdafx.h"
#include "TTMS_SCU_Studio_UI_Add.h"

void Studio_UI_add(USER *user)
{
	system("cls");
	BIOS_GOTO_BOX(22,100,5,25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	STUDIO *studio_add;
	studio_add = (STUDIO *)malloc(sizeof(STUDIO));
	TTMS_GotoXY(52, 6);
	printf_s("增加演出厅");
	TTMS_GotoXY(47, 9);
	printf_s("演出厅名称:");
	scanf_s("%s", studio_add->data.name, 30);
	TTMS_GotoXY(47, 11);
	printf_s("演出厅座位行数:");
	scanf_s("%d", &studio_add->data.rowsCount);
	TTMS_GotoXY(47, 13);
	printf_s("演出厅座位列数:");
	scanf_s("%d", &studio_add->data.colsCount);
	TTMS_GotoXY(47, 15);
	printf_s("演出厅行座位数:");
	scanf_s("%d", &studio_add->data.seatsCount);
	studio_add->data.id = EntKey_Srv_CompNewKey();
	Studio_Srv_Add(studio_add);
	TTMS_GotoXY(48, 18);
	printf_s("添加成功,任意键返回");
	_getch();
	Studio_UI_MgtEntry(user);
}
