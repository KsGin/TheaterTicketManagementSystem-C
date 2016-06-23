#include "stdafx.h"
#include "TTMS_SCU_Schedule_UI_Mod.h"

void Schedule_UI_Mod(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("请输入要修改的ID:");
	int ID;
	scanf_s("%d", &ID);
	SCHEDULE *schedule = Schedule_Srv_FetchByID(ID);
	if (schedule)
	{
		BIOS_GOTO_BOX(22, 100, 23, 22);
		BIOS_GOTO_BOX(58, 58, 8, 22);
		TTMS_GotoXY(35, 24);
		printf_s("请在右方对信息进行修改，若不需要修改请原封不动移过去");
		int NewStartTime_Day, NewStartTime_Month, NewStartTime_Year, NewStartTime_Hour, NewStartTime_Minute, NewStudioID, NewPlayID,NewSeatCountMax;
		char  key[15];
		TTMS_GotoXY(52, 6);
		printf_s("    第%d号演出计划        ", schedule->data.id);
		TTMS_GotoXY(25, 9);
		printf_s("放映厅ID: %d", schedule->data.studio_id);
		TTMS_GotoXY(25, 11);
		printf_s("剧目ID: %d", schedule->data.play_id);
		TTMS_GotoXY(25, 13);
		printf_s("计划开始时间:%d年%d月%d日%d时%d分", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);
		TTMS_GotoXY(25, 15);
		printf_s("最多座位数(票数): %d", schedule->data.seat_count);
		TTMS_GotoXY(60, 9);
		printf_s("修改后:");
		TTMS_GotoXY(60, 11);
		printf_s("修改后: ");
		TTMS_GotoXY(60, 13);
		printf_s("修改后: ");
		TTMS_GotoXY(60, 15);
		printf_s("修改后: ");
		TTMS_GotoXY(67, 9);
		scanf_s("%d", &NewStudioID);
		TTMS_GotoXY(67, 11);
		scanf_s("%d", &NewPlayID);
		TTMS_GotoXY(67, 13);
		scanf_s("%d%d%d%d%d", &NewStartTime_Year, &NewStartTime_Month,&NewStartTime_Day, &NewStartTime_Hour, &NewStartTime_Minute);
		TTMS_GotoXY(67, 15);
		scanf_s("%d", &NewSeatCountMax);
		schedule->data.play_id = NewPlayID;
		schedule->data.studio_id = NewStudioID;
		schedule->time.daytime.year = NewStartTime_Year;
		schedule->time.daytime.month = NewStartTime_Month;
		schedule->time.daytime.day = NewStartTime_Day;
		schedule->time.hour = NewStartTime_Hour;
		schedule->time.minute = NewStartTime_Minute;
		schedule->data.seat_count = NewSeatCountMax;
		TTMS_GotoXY(35, 24);
		printf_s("                                                       ");
		TTMS_GotoXY(52, 24);
		printf_s("Enter确认修改，Esc取消");
		strcpy_s(key, 15, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Schedule_Srv_Mod(schedule);
			TTMS_GotoXY(35, 24);
			printf_s("                                                     ");
			TTMS_GotoXY(50, 24);
			printf_s("修改成功,任意键退出！");
			_getch();
			Schedule_UI_MgtEntry(user);
		}
		if (strcmp(key, "Esc") == 0)
		{
			TTMS_GotoXY(35, 24);
			printf_s("                                                    ");
			TTMS_GotoXY(50, 24);
			printf_s("取消成功,任意键退出！");
			_getch();
			Schedule_UI_MgtEntry(user);
		}
	}
	else
	{
		TTMS_GotoXY(35, 24);
		printf_s("                                                       ");
		TTMS_GotoXY(50, 24);
		printf_s("无此剧目,按任意键退出");
		_getch();
		Schedule_UI_MgtEntry(user);
	}
}
