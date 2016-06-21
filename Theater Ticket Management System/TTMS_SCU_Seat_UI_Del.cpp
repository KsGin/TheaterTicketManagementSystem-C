#include "stdafx.h"
#include "TTMS_SCU_Seat_UI_Del.h"

int Seat_UI_Delete(USER *user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("删除演出厅座位");
	SEAT *seat;
	int Seat_ID;
	TTMS_GotoXY(45, 9);
	printf_s("请输入要删除的ID:");
	scanf_s("%d", &Seat_ID);
	seat = Seat_Perst_FetchByID(Seat_ID);
	if (seat == nullptr)
	{
		TTMS_GotoXY(50, 20);
		printf_s("该座位不存在");
		_getch();
		Seat_UI_MgtEntry(user);
	}
	else {
		TTMS_GotoXY(45, 12);
		printf_s("座位位于演出厅ID:%d", seat->data.RoomID);
		TTMS_GotoXY(45, 14);
		printf_s("座位列数:%d",seat->data.col);
		TTMS_GotoXY(45, 16);
		printf_s("座位行数:%d", seat->data.row);
		TTMS_GotoXY(52, 20);
		printf_s("Enter键继续删除!");
		TTMS_GotoXY(54, 22);
		char key[20];
		strcpy_s(key, 20, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Seat_Perst_DeleteByID(seat->data.id);
			EntKeySeat_Perst_CompKeyM();
			printf_s("删除成功");
			_getch();
			Seat_UI_MgtEntry(user);
		}
		else
		{
			Seat_UI_MgtEntry(user);
		}
	}
	return 0;
}
