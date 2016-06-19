#pragma once
typedef struct {
	int id;			//放映厅ID
	char name[30];	//放映厅名称
	int rowsCount;	//座位行数
	int colsCount;	//座位列数
	int seatsCount;
} studio_t;

//双向链表
typedef struct studio_node {
	studio_t data;				//实体数据
	struct studio_node *next;	//后向指针
	struct studio_node *prev;	//前向指针
} STUDIO;                                                                      
