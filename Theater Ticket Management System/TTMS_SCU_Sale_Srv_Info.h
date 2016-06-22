#pragma once
//交易类型，为售票或退票
typedef enum {
	SALE_SELL = 1,	//买票
	SALE_RETURN = -1	//退票
}sale_type_t;

// 用来统计的信息 ， 显示售票情况的。 如在某个时间段内售出多少票 ， 或者某个ticket_id , 这个要插到我的模块中去 ， 在买票的时候进行记录 。
typedef struct {
	long id;      		//销售记录ID
	char UserAcc[15];	//售票员账号
	int ticket_id;		//票ID
//	user_date_t date;	//处理日期
//	user_time_t time;	//处理时间
	int value;			//票价
	sale_type_t type; //交易类型
}sale_t;

//双向链表
typedef struct sale_node {
	sale_t data;
	struct sale_node *next, *prev;
} SALE;