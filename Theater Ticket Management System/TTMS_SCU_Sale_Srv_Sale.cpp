#include "stdafx.h"
#include "TTMS_SCU_Sale_Srv_Sale.h"

void Sale_Srv_SaleO(TICKET * ticket, USER *user)
{
	//ÐÞ¸ÄÆ±×´Ì¬
	//´æ´¢¶©µ¥ÐÅÏ¢
	ticket->data.status = TICKET_SOLD;
	Ticket_Perst_ModStatus(ticket);
	SALE *sale;
	sale = (SALE*)malloc(sizeof(SALE));
	sale->data.id = EntKeySale_Perst_CompNewKeys();
	sale->data.ticket_id = ticket->data.id;
	sale->data.type = SALE_SELL;
	strcpy_s(sale->data.UserAcc,15, user->USER_ACCOUT);
	sale->data.value = ticket->data.price;
	Sale_Perst_Insert(sale);
	EntKeySale_Perst_CompKeyP();
}
