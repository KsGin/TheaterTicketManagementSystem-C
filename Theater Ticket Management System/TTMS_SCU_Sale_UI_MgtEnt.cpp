#include "stdafx.h"
#include "TTMS_SCU_Sale_UI_MgtEnt.h"
void Sale_UI_Mgt_Entry(USER * user)
{
	Schedule_UI_Browe(user,1);
	TTMS_GotoXY(48, 27);
	printf_s("按任意键进入销售管理");
	TTMS_GotoXY(43, 27);
	printf_s("请输入交易类型(售票 = 1,退票 = 0):");
	int chiose = (int)(_getch()- 48);
	if (chiose == 1)
	{
		system("cls");
		BIOS_GOTO_BOX(22, 100, 5, 25);
		BIOS_GOTO_BOX(22, 100, 8, 7);
		TTMS_GotoXY(50, 6);
		printf_s("售票管理页面");
		TTMS_GotoXY(47, 9);
		printf_s("演出计划ID:");
		TTMS_GotoXY(47, 11);
		printf_s("座位行数:");
		TTMS_GotoXY(47, 13);
		printf_s("座位列数:");
		int ScheduleID, SeatRowCount,SeatColCount;
		TTMS_GotoXY(59, 9);
		scanf_s("%d", &ScheduleID);
		TTMS_GotoXY(57, 11);
		scanf_s("%d", &SeatRowCount);
		TTMS_GotoXY(57, 13);
		scanf_s("%d", &SeatColCount);
		SCHEDULE *schedule = Schedule_Srv_FetchByID(ScheduleID);
		if (!schedule)
		{
			TTMS_GotoXY(52, 24);
			printf_s("没有此演出信息!");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
		TICKET *ticket;
		ticket = (TICKET*)malloc(sizeof(TICKET));
		ticket->data.id = Ticket_Perst_FetchBySS(ScheduleID,Seat_Perst_FetchByRC(SeatRowCount, SeatColCount,schedule->data.studio_id));
		ticket = Ticket_Perst_FetchByID(schedule->data.studio_id);
		if (ticket)
		{
			_getch();
			ticket->data.seat_id = Seat_Perst_FetchByRC(SeatRowCount, SeatColCount, schedule->data.studio_id);
			Ticket_UI_ShowTicketByT(ticket);
		}
		else {
			printf_s("!!!!");
		}
	}
	else if (chiose == 2)
	{
		system("cls");
		BIOS_GOTO_BOX(22, 100, 5, 25);
		BIOS_GOTO_BOX(22, 100, 8, 7);
		TTMS_GotoXY(50, 6);
		printf_s("退票管理页面");
	}
	else {
		system("cls");
		TTMS_GotoXY(50, 15);
		printf_s("输入有误");
	}
}
