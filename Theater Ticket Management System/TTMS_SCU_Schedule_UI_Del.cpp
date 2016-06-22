#include "stdafx.h"
#include "TTMS_SCU_Schedule_UI_Del.h"

int Schedule_UI_Delete(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("删除演出计划");
	SCHEDULE *schedule;
	int Schedule_ID;
	TTMS_GotoXY(45, 9);
	printf_s("请输入要删除的ID:");
	scanf_s("%d", &Schedule_ID);
	schedule = Schedule_Srv_FetchByID(Schedule_ID);
	if (schedule == nullptr)
	{
		TTMS_GotoXY(50, 20);
		printf_s("该演出计划不存在");
		_getch();
		Schedule_UI_MgtEntry(user);
	}
	else {
		TTMS_GotoXY(45, 12);
		printf_s("演出厅ID:%d", schedule->data.studio_id);
		TTMS_GotoXY(45, 14);
		printf_s("剧目ID:%d", schedule->data.play_id);
		TTMS_GotoXY(45, 16);
		printf_s("座位总数:%d", schedule->data.seat_count);
		TTMS_GotoXY(45, 18);
		printf_s("放映开始时间:%d-%d-%d %d-%d", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);
		TTMS_GotoXY(52, 24);
		printf_s("Enter键继续删除!");
		char key[20];
		strcpy_s(key, 20, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Schedule_Srv_Delete(schedule->data.id);
			TTMS_GotoXY(52, 24);
			printf_s("                        ");
			TTMS_GotoXY(55, 24);
			printf_s("删除成功");
			_getch();
			Schedule_UI_MgtEntry(user);
		}
		else
		{
			Schedule_UI_MgtEntry(user);
		}
	}
	return 0;
}
