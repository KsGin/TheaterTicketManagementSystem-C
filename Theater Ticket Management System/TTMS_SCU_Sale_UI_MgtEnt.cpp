#include "stdafx.h"
#include "TTMS_SCU_Sale_UI_MgtEnt.h"
void Sale_UI_Mgt_Entry(USER * user)
{
	Schedule_UI_Browe(user,1);
	TTMS_GotoXY(48, 27);
	printf_s("按Enter进入销售管理,Esc退出");
	if (strcmp(GET_KEY(), "Esc") == 0)
	{
		Main_UI_MgtEntry(user);
	}
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
		int seat_id = Seat_Perst_FetchByRC(SeatRowCount, SeatColCount, schedule->data.studio_id);
		if (!seat_id)
		{
			TTMS_GotoXY(52, 24);
			printf_s("没有此座位信息!");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
		ticket = (TICKET*)malloc(sizeof(TICKET));
		ticket->data.id = Ticket_Perst_FetchBySS(ScheduleID, seat_id);
		ticket = Ticket_Perst_FetchByID(ticket->data.id);
	//	printf_s("%d    ", ticket->data.id);
		if (ticket)
		{
			if (ticket->data.status != TICKET_AVL)
			{
				TTMS_GotoXY(48, 24);
				printf_s("此座位票已售出或被预定!");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
			ticket->data.seat_id = Seat_Perst_FetchByRC(SeatRowCount, SeatColCount, schedule->data.studio_id);
			Ticket_UI_ShowTicketByT(ticket);
			TTMS_GotoXY(55, 24);
			printf_s("Enter确认售票");
			if (strcmp(GET_KEY(),"Enter") == 0)
			{
				//售票
				Sale_Srv_SaleO(ticket, user);
				TTMS_GotoXY(55, 24);
				printf_s("售票成功!       ");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
			else {
				TTMS_GotoXY(55, 24);
				printf_s("取消成功!         ");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
		}
		else {
			TTMS_GotoXY(52, 24);
			printf_s("没有此票信息!          ");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
	}
	else if (chiose == 0)
	{
		system("cls");
		BIOS_GOTO_BOX(22, 100, 5, 25);
		BIOS_GOTO_BOX(22, 100, 8, 7);
		TTMS_GotoXY(50, 6);
		printf_s("退票管理页面");
		TTMS_GotoXY(47, 9);
		printf_s("演出计划ID:");
		TTMS_GotoXY(47, 11);
		printf_s("座位行数:");
		TTMS_GotoXY(47, 13);
		printf_s("座位列数:");
		int ScheduleID, SeatRowCount, SeatColCount;
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
		int seat_id = Seat_Perst_FetchByRC(SeatRowCount, SeatColCount, schedule->data.studio_id);
		if (!seat_id)
		{
			TTMS_GotoXY(52, 24);
			printf_s("没有此座位信息!");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
		ticket = (TICKET*)malloc(sizeof(TICKET));
		ticket->data.id = Ticket_Perst_FetchBySS(ScheduleID, seat_id);
	//	printf_s("%d", ticket->data.id);
		ticket = Ticket_Perst_FetchByID(ticket->data.id);
		if (ticket)
		{
	//		printf_s("%d", ticket->data.id);
	//		_getch();
			if (ticket->data.status == TICKET_AVL)
			{
				TTMS_GotoXY(48, 24);
				printf_s("此座位票尚未售出!");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
			ticket->data.seat_id = seat_id;
			Ticket_UI_ShowTicketByT(ticket);
			TTMS_GotoXY(55, 24);
			printf_s("Enter确认退票");
			if (strcmp(GET_KEY(), "Enter") == 0)
			{
				//售票
				Sale_Srv_SaleI(ticket, user);
				TTMS_GotoXY(55, 24);
				printf_s("退票成功!       ");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
			else {
				TTMS_GotoXY(55, 24);
				printf_s("取消成功!         ");
				_getch();
				Sale_UI_Mgt_Entry(user);
			}
		}
		else {
			TTMS_GotoXY(52, 24);
			printf_s("没有此票信息!          ");
			_getch();
			Sale_UI_Mgt_Entry(user);
		}
	}
	else {
		system("cls");
		TTMS_GotoXY(50, 15);
		printf_s("输入有误");
	}
}
