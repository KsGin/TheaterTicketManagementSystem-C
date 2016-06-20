#include "stdafx.h"
#include "TTMS_SCU_Studio_UI_LookByP.h"

void Studio_UI_LookByPage(int Page)
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
	BIOS_GOTO_BOX(30, 30, 5, 22);
	BIOS_GOTO_BOX(65, 65, 5, 22);
	BIOS_GOTO_BOX(83, 83, 5, 22);
	BIOS_GOTO_BOX(100, 100, 5, 22);
	TTMS_GotoXY(24, 6);
	printf_s("ID");
	TTMS_GotoXY(45, 6);
	printf_s("名称");
	TTMS_GotoXY(70 ,6);
	printf_s("座位行数");
	TTMS_GotoXY(88, 6);
	printf_s("座位列数");
	TTMS_GotoXY(37, 24);
	printf_s("Left上一页  Right下一页  Esc返回上一层              PAGE:%d",Page);
	for (int i = ((Page-1)*5)+1; i <= (Page)*5; i++)
	{
		STUDIO *studio = Studio_Srv_FetchByID(i);
		if (!studio)
		{
			break;
		}
		TTMS_GotoXY(24, 9 + (i - 5 * (Page - 1)-1) * 3);
		printf_s("%d", studio->data.id);
		TTMS_GotoXY(45, 9 + (i - 5 * (Page - 1)-1) * 3);
		printf_s("%s", studio->data.name);
		TTMS_GotoXY(70, 9 + (i - 5 * (Page - 1)-1) * 3);
		printf_s("%d", studio->data.rowsCount);
		TTMS_GotoXY(88, 9 + (i - 5 * (Page - 1)-1) * 3);
		printf_s("%d", studio->data.colsCount);

	}
}
