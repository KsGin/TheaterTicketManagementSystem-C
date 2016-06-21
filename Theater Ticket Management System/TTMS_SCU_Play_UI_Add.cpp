#include "stdafx.h"
#include "TTMS_SCU_Play_UI_Add.h"

void Play_UI_Add(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	PLAY *Play_add;
	Play_add = (PLAY *)malloc(sizeof(PLAY));
	TTMS_GotoXY(52, 6);
	printf_s("增加剧目信息");
	TTMS_GotoXY(47, 9);
	printf_s("剧目名称:");
	TTMS_GotoXY(47, 11);
	printf_s("剧目类型:");
	TTMS_GotoXY(47, 13);
	printf_s("剧目等级:");
	TTMS_GotoXY(47, 15);
	printf_s("剧目时长:");
	TTMS_GotoXY(47, 15);
	printf_s("剧目票务价格:");
	TTMS_GotoXY(48, 18);
	printf_s("添加成功,任意键返回");
	_getch();
	Studio_UI_MgtEntry(user);
}
