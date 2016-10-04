#include "stdafx.h"
#include "TTMS_SCU_Play_UI_Add.h"

void Play_UI_Add(USER* user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	PLAY* Play_add;
	Play_add = (PLAY *)malloc(sizeof(PLAY));
	TTMS_GotoXY(52, 6);
	printf_s("增加剧目信息");
	TTMS_GotoXY(47, 9);
	printf_s("剧目名称:");
	TTMS_GotoXY(47, 11);
	printf_s("出产地区:");
	TTMS_GotoXY(47, 13);
	printf_s("剧目时长:");
	TTMS_GotoXY(47, 15);
	printf_s("剧目价格:");
	TTMS_GotoXY(35, 17);
	printf_s("类型:");
	TTMS_GotoXY(46, 17);
	printf_s("电影");
	TTMS_GotoXY(61, 17);
	printf_s("歌剧");
	TTMS_GotoXY(76, 17);
	printf_s("音乐会");
	TTMS_GotoXY(35, 19);
	printf_s("等级:");
	TTMS_GotoXY(46, 19);
	printf_s("小孩");
	TTMS_GotoXY(61, 19);
	printf_s("青年");
	TTMS_GotoXY(76, 19);
	printf_s("成人");
	TTMS_GotoXY(57, 9);
	scanf_s("%s", Play_add->data.name, 31);
	TTMS_GotoXY(57, 11);
	scanf_s("%s", Play_add->data.area, 9);
	TTMS_GotoXY(57, 13);
	scanf_s("%d", &Play_add->data.duration);
	TTMS_GotoXY(57, 15);
	scanf_s("%d", &Play_add->data.price);
	GET_OC(43, 17, 73, 17, 0, 15, "->", 1, 0);
	switch (GET_CURSOR_X())
	{
	case 45: Play_add->data.type = PLAY_TYPE_FLIM;
		break;
	case 60: Play_add->data.type = PLAY_TYPE_OPEAR;
		break;
	case 75: Play_add->data.type = PLAY_TYPE_CONCERT;
		break;
	default:
		break;
	}
	GET_OC(43, 19, 73, 19, 0, 15, "->", 1, 0);
	switch (GET_CURSOR_X())
	{
	case 45: Play_add->data.rating = PLAY_RATE_CHILD;
		break;
	case 60: Play_add->data.rating = PLAY_RATE_TEENAGE;
		break;
	case 75: Play_add->data.rating = PLAY_RATE_ADULT;
		break;
	default:
		break;
	}
	if (Play_Srv_Add(Play_add) == 0)
	{
		TTMS_GotoXY(48, 23);
		printf_s("添加失败,完全相同剧目已存在");
		_getch();
		Play_UI_MgtEntry(user);
	}
	TTMS_GotoXY(48, 23);
	printf_s("添加成功,任意键返回");
	_getch();
	Play_UI_MgtEntry(user);
}
