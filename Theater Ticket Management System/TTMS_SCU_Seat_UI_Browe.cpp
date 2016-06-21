#include "stdafx.h"
#include "TTMS_SCU_Seat_UI_Browe.h"

void Seat_UI_Browe(USER * user)
{
	system("cls");
	int key = EntKeySeat_Perst_CompNewKeys();
	for (int i = 1; i < key; i++)
	{
		SEAT *seat = Seat_Srv_FetchByID(i);
		if (seat)
		{
			printf_s("\t\t\t\t\t        第%d号座位\n        ", seat->data.id);    
			printf_s("\t\t\t\t\t放映厅ID: %d\n", seat->data.RoomID);
			printf_s("\t\t\t\t\t座位行数: %d\n", seat->data.row);
			printf_s("\t\t\t\t\t座位列数: %d\n", seat->data.col); 
			printf_s("\t\t\t\t\t座位状态:");
			switch ((SEAT_STATUS)seat->data.status)
			{
			case SEAT_GOOD:printf_s("可用\n"); break;
			case SEAT_BROKEN:printf_s("破损\n"); break;
			case SEAT_NODE:printf_s("无座位\n"); break;
			default:
				break;
			}
			printf_s("\n");
		}
	}
	_getch();
	Seat_UI_MgtEntry(user);
}
