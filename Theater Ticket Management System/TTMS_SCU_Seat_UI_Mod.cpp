#include "stdafx.h"
#include "TTMS_SCU_Seat_UI_Mod.h"

void Seat_UI_Mod(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("请输入要修改的ID:");
	int ID;
	scanf_s("%d", &ID);
	SEAT *seat = Seat_Srv_FetchByID(ID);
	if (seat)
	{
		int NewStatus;
		char  key[15];
		TTMS_GotoXY(52, 6);
		printf_s("    第%d号座位        ",seat->data.id);
		TTMS_GotoXY(48, 9);
		printf_s("放映厅ID: %d", seat->data.RoomID);
		TTMS_GotoXY(48, 11);
		printf_s("座位行数: %d", seat->data.row);
		TTMS_GotoXY(48, 13);
		printf_s("座位列数: %d", seat->data.col);
		TTMS_GotoXY(48, 15);
		printf_s("座位状态:");
		switch (seat->data.status)
		{     
		case SEAT_GOOD:printf_s("可用"); break;
		case SEAT_BROKEN:printf_s("破损"); break;
		case SEAT_NODE:printf_s("无座位"); break;
		default:
			break;
		}
		TTMS_GotoXY(45, 17);
		printf_s("您只可修改座位状态，其他请添加座位");
		TTMS_GotoXY(45, 19);
		printf_s("请输入座位状态信息(可用:1,破损:9)");
		scanf_s("%d",&NewStatus);
		if (NewStatus != 9 && NewStatus != 1)
		{
			TTMS_GotoXY(50, 20);
			printf_s("输入信息有误 !           ");
		}
		else
		{
			seat->data.status = (SEAT_STATUS)NewStatus;
		}
		TTMS_GotoXY(50, 23);
		printf_s("Enter确认修改，Esc取消");
		strcpy_s(key, 15, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Seat_Srv_Mod(seat, NewStatus);
			TTMS_GotoXY(50, 23);
			printf_s("修改成功,任意键退出！");
			_getch();
			Seat_UI_MgtEntry(user);
		}
		if (strcmp(key, "Esc") == 0)
		{
			TTMS_GotoXY(50, 23);
			printf_s("取消成功,任意键退出！");
			_getch();
			Seat_UI_MgtEntry(user);
		}
	}
	else {
		TTMS_GotoXY(45, 23);
		printf_s("无此座位,按任意键退出");
		_getch();
		Seat_UI_MgtEntry(user);
	}
}
