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
	printf_s("出产地区:");
	TTMS_GotoXY(47, 13);
	printf_s("剧目时长:");
	TTMS_GotoXY(47, 15);
	printf_s("剧目价格:");
//	TTMS_GotoXY(47, 15);
//	printf_s("剧目票务价格:");
//	TTMS_GotoXY(48, 18);
	TTMS_GotoXY(57, 9);
	scanf_s("%s", Play_add->data.name,31);
	TTMS_GotoXY(57, 11);
	scanf_s("%s", Play_add->data.area,9);
	TTMS_GotoXY(57, 13);
	scanf_s("%d", &Play_add->data.duration);
	TTMS_GotoXY(57, 15);
	scanf_s("%d", &Play_add->data.price);
	if (Play_Srv_Add(Play_add) == 0)
	{
		TTMS_GotoXY(48, 20);
		printf_s("添加失败,完全相同剧目已存在");
		_getch();
		Play_UI_MgtEntry(user);
	}
	TTMS_GotoXY(48, 20);
	printf_s("添加成功,任意键返回");
	_getch();
	Play_UI_MgtEntry(user);
}
