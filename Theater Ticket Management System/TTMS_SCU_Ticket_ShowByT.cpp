#include "stdafx.h"
#include "TTMS_SCU_Ticket_ShowByT.h"

int Ticket_UI_ShowTicketByT(TICKET * ticket)
{
	system("cls");
	TTMS_GotoXY(55, 6);
	printf_s("没人来大剧院");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	auto *schedule = Schedule_Srv_FetchByID(ticket->data.schedule_id);
	if (!schedule)
	{
		TTMS_GotoXY(50, 24);
		printf_s("无此演出计划的信息");
	}
	else {
		for (auto i = 11; i < 21; i++)
		{
			TTMS_GotoXY(30, i);
			printf_s("*");
			TTMS_GotoXY(92, i);
			printf_s("*");
		}
		for (auto i = 30; i < 92; i++)
		{
			TTMS_GotoXY(i, 11);
			printf_s("*");
			TTMS_GotoXY(i, 21);
			printf_s("*");
		}
		TTMS_GotoXY(92, 21);
		printf_s("*");
		TTMS_GotoXY(45, 13);
		printf_s("没人来剧院");
		TTMS_GotoXY(33, 15);
		auto *play = Play_Srv_FetchByID(schedule->data.play_id);
		switch (play->data.type)
		{
		case PLAY_TYPE_FLIM:printf_s("电影"); break;
		case PLAY_TYPE_OPEAR:printf_s("歌剧"); break;
		case PLAY_TYPE_CONCERT:printf_s("音乐会"); break;
		default:
			break;
		}
		printf_s("名称:%s", play->data.name);
		TTMS_GotoXY(70, 15);
		printf_s("#适用于");
		switch (play->data.rating)
		{
		case PLAY_RATE_CHILD:printf_s("儿童"); break;
		case PLAY_RATE_TEENAGE:printf_s("青年"); break;
		case PLAY_RATE_ADULT:printf_s("成人"); break;
		default:
			break;
		}
		printf_s("观众#");
		TTMS_GotoXY(33, 17);
		printf_s("播放地址:");
		auto *studio = Studio_Srv_FetchByID(schedule->data.studio_id);
		printf_s("%s演出厅", studio->data.name);
		TTMS_GotoXY(70, 17);
		printf_s("全片时长:%d分钟", play->data.duration);
		TTMS_GotoXY(33, 19);
		printf_s("开始时间 %d年%d月%d日%d时%d分", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);
		TTMS_GotoXY(73, 19);
		printf_s("票价:￥%d", play->data.price);
		auto *seat = Seat_Srv_FetchByID(ticket->data.seat_id);
		TTMS_GotoXY(71, 13);
		printf_s("##%d排%d列##", seat->data.row, seat->data.col);
	}
	_getch();
	return 0;
}
