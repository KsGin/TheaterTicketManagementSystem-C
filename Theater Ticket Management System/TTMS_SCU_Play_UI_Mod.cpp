#include "stdafx.h"
#include "TTMS_SCU_Play_UI_Mod.h"

void Play_UI_Mod(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("请输入要修改的ID:");
	int ID;
	scanf_s("%d", &ID);
	PLAY *play = Play_Srv_FetchByID(ID);
	if (play)
	{
		BIOS_GOTO_BOX(22, 100, 23, 22);
		BIOS_GOTO_BOX(58, 58, 8, 22);
		TTMS_GotoXY(35, 24);
		printf_s("请在右方对信息进行修改，若不需要修改请原封不动移过去");
		int NewDuration, NewType, NewRating, NewPrice;
		char  key[15], NewArea[9], NewName[30];
		TTMS_GotoXY(52, 6);
		printf_s("    第%d号剧目        ", play->data.id);
		TTMS_GotoXY(25, 9);
		printf_s("剧目名称: %s", play->data.name);
		TTMS_GotoXY(25, 11);
		printf_s("生产地区: %s", play->data.area);
		TTMS_GotoXY(25, 13);
		printf_s("剧目时长: %d", play->data.duration);
		TTMS_GotoXY(25, 15);
		printf_s("剧目票价格: %d", play->data.price);
		TTMS_GotoXY(25, 17);
		printf_s("剧目类型:");
		switch (play->data.type)
		{
		case PLAY_TYPE_FLIM:printf_s("电影");
		case PLAY_TYPE_OPEAR:printf_s("歌剧");
		case PLAY_TYPE_CONCERT:printf_s("音乐会");
		default:
			break;
		}
		TTMS_GotoXY(25, 19);
		printf_s("剧目类型:");
		switch (play->data.rating)
		{
		case PLAY_RATE_CHILD:printf_s("儿童");
		case PLAY_RATE_TEENAGE:printf_s("青年");
		case PLAY_RATE_ADULT:printf_s("成人");
		default:
			break;
		}
		TTMS_GotoXY(60, 9);
		printf_s("修改后:");
		TTMS_GotoXY(60, 11);
		printf_s("修改后: ");
		TTMS_GotoXY(60, 13);
		printf_s("修改后: ");
		TTMS_GotoXY(60, 15);
		printf_s("修改后: ");
		TTMS_GotoXY(60, 17);
		printf_s("修改后:(电影=1,歌剧=2,音乐会=3):");
		TTMS_GotoXY(60, 19);
		printf_s("修改后:(儿童=1,青年=2,成人=3):");
		TTMS_GotoXY(67, 9);
		scanf_s("%s", NewName,31);
		TTMS_GotoXY(67, 11);
		scanf_s("%s", NewArea,9);
		TTMS_GotoXY(67, 13);
		scanf_s("%d", &NewDuration);
		TTMS_GotoXY(67, 15);
		scanf_s("%d", &NewPrice);
		TTMS_GotoXY(92, 17);
		scanf_s("%d", &NewType);
		TTMS_GotoXY(92, 19);
		scanf_s("%d", &NewRating);
		if (NewType > 3 && NewType < 1)
		{
			TTMS_GotoXY(35 , 24);
			printf_s("                                                    ");
			TTMS_GotoXY(50, 24);
			printf_s("类型输入信息有误 !           ");
		}
		else if (NewRating > 3 && NewRating < 1)
		{
			TTMS_GotoXY(35, 24);
			printf_s("                                                     ");
			TTMS_GotoXY(50, 24);
			printf_s("等级输入信息有误 !           ");
		}
		else
		{
			strcpy_s(play->data.name,31,NewName);
			strcpy_s(play->data.area, 31, NewArea);
			play->data.duration = NewDuration;
			play->data.price = NewPrice;
			play->data.type = (play_type_t)NewType;
			play->data.rating = (play_rating_t)NewRating;
		}
		TTMS_GotoXY(35, 24);
		printf_s("                                                       ");
		TTMS_GotoXY(52, 24);
		printf_s("Enter确认修改，Esc取消");
		strcpy_s(key, 15, GET_KEY());
		if (strcmp(key, "Enter") == 0)
		{
			Play_Srv_Mod(play);
			TTMS_GotoXY(35, 24);
			printf_s("                                                     ");
			TTMS_GotoXY(50, 24);
			printf_s("修改成功,任意键退出！");
			_getch();
			Play_UI_MgtEntry(user);
		}
		if (strcmp(key, "Esc") == 0)
		{
			TTMS_GotoXY(35, 24);
			printf_s("                                                    ");
			TTMS_GotoXY(50, 24);
			printf_s("取消成功,任意键退出！");
			_getch();
			Play_UI_MgtEntry(user);
		}
	}
	else 
	{
		TTMS_GotoXY(35, 24);
		printf_s("                                                       ");
		TTMS_GotoXY(50, 24);
		printf_s("无此剧目,按任意键退出");
		_getch();
		Play_UI_MgtEntry(user);
	}
}

