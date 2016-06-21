#pragma once
typedef struct {//演出计划类型定义
	int id;            //演出计划ID号
	int play_id;       //演出的剧目ID号
	int studio_id;     //演出的放映厅ID号
//	user_date_t date;  //演出日期
//	user_time_t time;  //演出时间
	int seat_count;    //座位数量
}schedule_t;

typedef struct {
	int year;
	int month;
	int day;
}DAY;

typedef struct {
	DAY daytime;
	int hour;
	int minute;
}TIME;

typedef struct schedule_node {
	schedule_t data;
	TIME time;
	struct schedule_node *next;
	struct schedule_node *prev;
} SCHEDULE;