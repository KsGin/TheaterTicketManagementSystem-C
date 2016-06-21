#include "stdafx.h"
#include "TTMS_SCU_Play_UI_Del.h"

int Play_UI_Delete(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("删除剧目信息");
	PLAY *play;
	int Seat_ID;
	TTMS_GotoXY(45, 9);
	printf_s("请输入要删除的ID:");
	scanf_s("%d", &Seat_ID);
	play = Play_Perst_FetchByID(Seat_ID);
	if (play == nullptr)
	{
		TTMS_GotoXY(50, 20);
		printf_s("该剧目不存在");
		_getch();
		Play_UI_MgtEntry(user);
	}
	else {
		TTMS_GotoXY(45, 12);
		printf_s("剧目名称:%s", play->data.name);
		TTMS_GotoXY(45, 14);
		printf_s("出产地区:%s", play->data.area);
		TTMS_GotoXY(45, 16);
		printf_s("全片时长:%d", play->data.duration);
		TTMS_GotoXY(52, 20);
		printf_s("Enter键继续删除!");
		TTMS_GotoXY(54, 22);
		char key[20];
		strcpy_s(key, 20, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Play_Perst_DeleteByID(play->data.id);
			EntKeyPlay_Perst_CompKeyM();
			printf_s("删除成功");
			_getch();
			Play_UI_MgtEntry(user);
		}
		else
		{
			Play_UI_MgtEntry(user);
		}
	}
	return 0;
}
