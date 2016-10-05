#include "stdafx.h"
#include <Windows.h>
#include "TTMS_SCU_Sale_UI_ShowSchedule.h"
#define MAXSCHEDULE 100
void Sale_UI_ShowSchedule(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("请输入查询的剧目ID:");
	auto KeyMax = EntKeySchedule_Perst_CompNewKeys();
	int ID,ScheCount = 0,ScheIdArr[MAXSCHEDULE];
	scanf_s("%d", &ID);
	for (auto i = 1; i <= KeyMax; i++)
	{
		auto *schedule = Schedule_Srv_FetchByID(i);
		if (schedule->data.play_id == ID)
		{
			ScheIdArr[ScheCount] = schedule->data.id;
			++ScheCount;
			TTMS_GotoXY(52, 13);
			printf_s("已查找到%d个演出计划",ScheCount);
			Sleep(500);
		}
	}
	Schedule_UI_Browe(user, ScheIdArr, ScheCount);

}
