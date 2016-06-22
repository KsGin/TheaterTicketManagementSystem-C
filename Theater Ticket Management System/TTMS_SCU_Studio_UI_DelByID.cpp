#include "stdafx.h"
#include "TTMS_SCU_Studio_UI_DelByID.h"

void Studio_UI_Delete(USER *User)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("删除演出厅");
	STUDIO *studio;
	int Studio_ID;
	TTMS_GotoXY(45, 9);
	printf_s("请输入要删除的ID:");
	scanf_s("%d", &Studio_ID);
	studio = Studio_Perst_FetchByID(Studio_ID);
	if (studio == nullptr)
	{
		TTMS_GotoXY(50, 20);
		printf_s("该演出厅不存在");
		_getch();
		Studio_UI_MgtEntry(User);
	}
	else {
		TTMS_GotoXY(45, 12);
		printf_s("演出厅名字:%s", studio->data.name);
		TTMS_GotoXY(45, 14);
		printf_s("座位列数:%d", studio->data.rowsCount);
		TTMS_GotoXY(45, 16);
		printf_s("座位行数:%d", studio->data.colsCount);
		TTMS_GotoXY(52, 20);
		printf_s("Enter键继续删除!");
		TTMS_GotoXY(54, 22);
		char key[20];
		strcpy_s(key, 20, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Seat_Srv_DelAll(studio);
			Studio_Perst_DeleteByID(Studio_ID);
			EntKey_Perst_CompKeyM();
			printf_s("删除成功");
			_getch();
			Studio_UI_MgtEntry(User);
		}
		else
		{
			Studio_UI_MgtEntry(User);
		}
	}
}
