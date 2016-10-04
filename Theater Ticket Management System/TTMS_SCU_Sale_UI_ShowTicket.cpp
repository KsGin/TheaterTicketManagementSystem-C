#include "stdafx.h"
#include "TTMS_SCU_Sale_UI_ShowTicket.h"

void Sale_UI_ShowTicket(USER* user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("请输入查询的演出计划ID:");
	int ID;
	scanf_s("%d", &ID);
	SCHEDULE* schedule = Schedule_Srv_FetchByID(ID);
	if (!schedule)
	{
		TTMS_GotoXY(50, 24);
		printf_s("无此演出计划的信息");
	}
	else
	{
		for (int i = 11; i < 21; i++)
		{
			TTMS_GotoXY(30, i);
			printf_s("*");
			TTMS_GotoXY(92, i);
			printf_s("*");
		}
		for (int i = 30; i < 92; i++)
		{
			TTMS_GotoXY(i, 11);
			printf_s("*");
			TTMS_GotoXY(i, 21);
			printf_s("*");
		}
		TTMS_GotoXY(92, 21);
		printf_s("*");
		TTMS_GotoXY(55, 13);
		printf_s("没人来剧院");
		TTMS_GotoXY(33, 15);
		PLAY* play = Play_Srv_FetchByID(schedule->data.play_id);
		switch (play->data.type)
		{
		case PLAY_TYPE_FLIM: printf_s("电影");
			break;
		case PLAY_TYPE_OPEAR: printf_s("歌剧");
			break;
		case PLAY_TYPE_CONCERT: printf_s("音乐会");
			break;
		default:
			break;
		}
		printf_s("名称:%s", play->data.name);
		TTMS_GotoXY(70, 15);
		printf_s("#适用于");
		switch (play->data.rating)
		{
		case PLAY_RATE_CHILD: printf_s("儿童");
			break;
		case PLAY_RATE_TEENAGE: printf_s("青年");
			break;
		case PLAY_RATE_ADULT: printf_s("成人");
			break;
		default:
			break;
		}
		printf_s("观众#");
		TTMS_GotoXY(33, 17);
		printf_s("播放地址:");
		STUDIO* studio = Studio_Srv_FetchByID(schedule->data.studio_id);
		printf_s("%s演出厅", studio->data.name);
		TTMS_GotoXY(70, 17);
		printf_s("全片时长:%d分钟", play->data.duration);
		TTMS_GotoXY(33, 19);
		printf_s("开始时间 %d年%d月%d日%d时%d分", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);
		TTMS_GotoXY(73, 19);
		printf_s("票价:￥%d", play->data.price);
	}
	_getch();
	Main_UI_MgtEntry(user);
}
