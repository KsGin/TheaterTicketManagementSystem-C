#include "stdafx.h"
#include "TTMS_SCU_Seat_UI_Add.h"

void Seat_UI_Add(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	SEAT *seat;
	STUDIO *studio;
	seat = static_cast<SEAT *>(malloc(sizeof(SEAT)));
	TTMS_GotoXY(52, 6);
	printf_s("增加座位");
	TTMS_GotoXY(47, 9);
	printf_s("所在演出厅ID:");
	TTMS_GotoXY(47, 11);
	printf_s("座位所在行数:");
	TTMS_GotoXY(47, 13);
	printf_s("座位所在列数:");
	TTMS_GotoXY(38, 15);
	printf_s("座位有");
	TTMS_GotoXY(53, 15);
	printf_s("座位无");
	TTMS_GotoXY(68, 15);
	printf_s("座位损坏");
	TTMS_GotoXY(61, 9);
	scanf_s("%d", &seat->data.RoomID);
	TTMS_GotoXY(61, 11);
	scanf_s("%d", &seat->data.row);
	TTMS_GotoXY(61, 13);
	scanf_s("%d", &seat->data.col);
	auto i = GET_OC(35, 15, 65, 75, 0, 15, "->", 1, 0);
	switch (GET_CURSOR_X())
	{
	case 37:seat->data.status = SEAT_GOOD; break;
	case 52:seat->data.status = SEAT_NODE; break;
	case 67:seat->data.status = SEAT_BROKEN; break;
	default:
		break;
	}
	if (!(studio = Studio_Srv_FetchByID(seat->data.RoomID))) {
		TTMS_GotoXY(48, 20);
		printf_s("无此演出厅，任意键返回");
		_getch();
		Seat_UI_MgtEntry(user);
	}
	else if (seat->data.row > studio->data.rowsCount || seat->data.col > studio->data.colsCount )
	{
		TTMS_GotoXY(48, 20);
		printf_s("第%d号演出厅无此座位行列数",studio->data.id);
		_getch();
		Seat_UI_MgtEntry(user);
	}
	if (Seat_Srv_Add(seat) == 0)
	{
		TTMS_GotoXY(48, 20);
		printf_s("第%d号演出厅已经有此座位的信息", studio->data.id);
		_getch();
		Seat_UI_MgtEntry(user);
	}
	TTMS_GotoXY(48, 18);
	printf_s("添加成功,任意键返回");
	_getch();
	Seat_UI_MgtEntry(user);

}
