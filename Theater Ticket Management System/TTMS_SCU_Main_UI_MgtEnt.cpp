#include "stdafx.h"
#include "TTMS_SCU_Account_UI_MgtEnt.h"

void Main_UI_MgtEntry(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("欢迎回来,%s", user->USER_NAME);
	TTMS_GotoXY(45, 24);
	printf_s("按UP/DOWN选择,ENTER确认,ESC注销登录");
	BIOS_GOTO_BOX(22, 100, 23, 22);
	if (user->power == 0)
	{
		TTMS_GotoXY(47, 9);
		printf_s("No1:系统用户管理");
		TTMS_GotoXY(47, 11);
		printf_s("No2:演出厅管理");
		TTMS_GotoXY(47, 13);
		printf_s("No3:恢复出厂化");
		if (GET_OC(44, 9, 44, 13, 2, 1, "->", 0, 1) == 1) {
			switch (GET_CURSOR_Y())
			{
			case 9:Account_UI_MgtEntry(user); break;
			case 11:Studio_UI_MgtEntry(user); break;
			case 13:
				system("cls");
				remove("Account.dat");
				remove("Studio.dat");
				remove("EntityKey.dat");
				remove("Seat.dat");
				remove("EntityKeySeat.dat");
				remove("Play.dat");
				remove("EntityKeyPlay.dat");
				remove("Schedule.dat");
				remove("EntityKeySchedule.dat");
				remove("EntityKeyTicket.dat");
				remove("Ticket.dat");
				remove("EntityKeySale.dat");
				remove("Sale.dat");
				TTMS_INITIAL();
				exit(0);
			default:
				break;
			}
		}
		else {
			SysLogin();
		}
	}
	else if(user->power == 1){
		TTMS_GotoXY(47, 9);
		printf_s("No1:剧目管理");
		TTMS_GotoXY(47, 11);
		printf_s("No2:查询演出");
		TTMS_GotoXY(47, 13);
		printf_s("No3:查询演出票");
		TTMS_GotoXY(47, 15);
		printf_s("No4:分析销售数据");
		TTMS_GotoXY(47, 17);
		printf_s("No5:统计销售额");
		TTMS_GotoXY(47, 19);
		printf_s("No5:修改密码");
		if (GET_OC(44, 9, 44, 19, 2, 1, "->", 0, 1) == 1) {
			switch (GET_CURSOR_Y())
			{
			case 9: Play_UI_MgtEntry(user); break;
			case 11:Sale_UI_ShowSchedule(user);  break;
			case 13:Sale_UI_ShowTicket(user); break;
			case 15:SaleData_UI_Analysis(user); break;
			case 17:SaleData_UI_Money(user, user->power); break;
			case 19:Account_UI_ModPassword(user); break;
			default:
				break;
			}
		}
		else {
			SysLogin();
		}
	}
	else if (user->power == 2) {
		TTMS_GotoXY(47, 9);
		printf_s("No1:售票");
		TTMS_GotoXY(47, 11);
		printf_s("No2:查询演出");
		TTMS_GotoXY(47, 13);
		printf_s("No3:查询演出票");
		TTMS_GotoXY(47, 15);
		printf_s("No4:统计销售额");
		TTMS_GotoXY(47, 17);
		printf_s("No5:修改密码");
		if (GET_OC(44, 9, 44, 17, 2, 1, "->", 0, 1) == 1) {
			switch (GET_CURSOR_Y())
			{
			case 9: Sale_UI_Mgt_Entry(user); break;
			case 11:Sale_UI_ShowSchedule(user); break;
			case 13:Sale_UI_ShowTicket(user); break;
			case 15:SaleData_UI_Money(user, user->power); break;
			case 17:Account_UI_ModPassword(user); break;
			default:
				break;
			}
		}
		else {
			SysLogin();
		}
	}
}
