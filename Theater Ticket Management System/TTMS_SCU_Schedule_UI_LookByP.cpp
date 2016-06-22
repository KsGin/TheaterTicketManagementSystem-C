#include "stdafx.h"
#include "TTMS_SCU_Schedule_UI_LookByP.h"

void Schedule_UI_LookByPage(int Page)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 11, 10);
	BIOS_GOTO_BOX(22, 100, 14, 13);
	BIOS_GOTO_BOX(22, 100, 17, 16);
	BIOS_GOTO_BOX(22, 100, 20, 19);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(30, 45, 5, 22);
//	BIOS_GOTO_BOX(45, 45, 5, 22);
	BIOS_GOTO_BOX(60, 70, 5, 22);
	BIOS_GOTO_BOX(100, 100, 5, 22);
	TTMS_GotoXY(24, 6);
	printf_s("ID");
	TTMS_GotoXY(35, 6);
	printf_s("演出厅ID");
	TTMS_GotoXY(50, 6);
	printf_s("剧目ID");
	TTMS_GotoXY(63, 6);
	printf_s("票总数");
	TTMS_GotoXY(80, 6);
	printf_s("开始时间");
	TTMS_GotoXY(37, 24);
	printf_s("Left上一页  Right下一页  Esc返回上一层              PAGE:%d", Page);
	for (int i = ((Page - 1) * 5) + 1; i <= (Page) * 5; i++)
	{
		SCHEDULE *schedule = Schedule_Perst_FetchByID(i);
		if (!schedule)
		{
			break;
		}
		TTMS_GotoXY(24, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.id);
		TTMS_GotoXY(37, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.studio_id);
		TTMS_GotoXY(52, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.play_id);
		TTMS_GotoXY(64, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.seat_count);
		TTMS_GotoXY(75, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d年%d月%d日%d时%d分", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);

	}
}

void Schedule_UI_LookByPage(int Arr[],int Page)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 11, 10);
	BIOS_GOTO_BOX(22, 100, 14, 13);
	BIOS_GOTO_BOX(22, 100, 17, 16);
	BIOS_GOTO_BOX(22, 100, 20, 19);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(30, 45, 5, 22);
//	BIOS_GOTO_BOX(45, 45, 5, 22);
	BIOS_GOTO_BOX(60, 70, 5, 22);
	BIOS_GOTO_BOX(100, 100, 5, 22);
	TTMS_GotoXY(24, 6);
	printf_s("ID");
	TTMS_GotoXY(35, 6);
	printf_s("演出厅ID");
	TTMS_GotoXY(50, 6);
	printf_s("剧目ID");
	TTMS_GotoXY(63, 6);
	printf_s("票总数");
	TTMS_GotoXY(80, 6);
	printf_s("开始时间");
	TTMS_GotoXY(37, 24);
	printf_s("Left上一页  Right下一页  Esc返回上一层              PAGE:%d", Page);
	for (int i = ((Page - 1) * 5) + 1; i <= (Page) * 5; i++)
	{
		SCHEDULE *schedule = Schedule_Perst_FetchByID(Arr[i-1]);
		if (!schedule)
		{
			break;
		}
		TTMS_GotoXY(24, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.id);
		TTMS_GotoXY(37, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.studio_id);
		TTMS_GotoXY(52, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.play_id);
		TTMS_GotoXY(64, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.seat_count);
		TTMS_GotoXY(75, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d年%d月%d日%d时%d分", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);

	}
}

void Schedule_UI_LookByPage( int Page, int i)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 11, 10);
	BIOS_GOTO_BOX(22, 100, 14, 13);
	BIOS_GOTO_BOX(22, 100, 17, 16);
	BIOS_GOTO_BOX(22, 100, 20, 19);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(30, 45, 5, 22);
	//	BIOS_GOTO_BOX(45, 45, 5, 22);
	BIOS_GOTO_BOX(60, 70, 5, 22);
	BIOS_GOTO_BOX(100, 100, 5, 22);
	TTMS_GotoXY(24, 6);
	printf_s("ID");
	TTMS_GotoXY(35, 6);
	printf_s("演出厅ID");
	TTMS_GotoXY(50, 6);
	printf_s("剧目ID");
	TTMS_GotoXY(63, 6);
	printf_s("票总数");
	TTMS_GotoXY(80, 6);
	printf_s("开始时间");
	TTMS_GotoXY(30, 24);
	printf_s("Left上一页  Right下一页  Esc返回上一层  （Esc结束浏览） PAGE:%d", Page);
	for (int i = ((Page - 1) * 5) + 1; i <= (Page) * 5; i++)
	{
		SCHEDULE *schedule = Schedule_Perst_FetchByID(i);
		if (!schedule)
		{
			break;
		}
		TTMS_GotoXY(24, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.id);
		TTMS_GotoXY(37, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.studio_id);
		TTMS_GotoXY(52, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.play_id);
		TTMS_GotoXY(64, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d", schedule->data.seat_count);
		TTMS_GotoXY(75, 9 + (i - 5 * (Page - 1) - 1) * 3);
		printf_s("%d年%d月%d日%d时%d分", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);

	}
}
