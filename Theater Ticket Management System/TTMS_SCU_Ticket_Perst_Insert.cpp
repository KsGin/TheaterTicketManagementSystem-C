#include "stdafx.h"
#include "TTMS_SCU_Ticket_Perst_Insert.h"

int Ticket_Perst_Insert(TICKET * ticket)
{
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, "Ticket.dat", "ab+") != 0))
	{
		TTMS_GotoXY(55, 3);
		printf_s("File Code:%d error!", err);
		fclose(fp);
		exit(1);
	}
	else
	{
		fwrite(ticket, sizeof(TICKET), 1, fp);
		fclose(fp);
	}
	return 0;
}
