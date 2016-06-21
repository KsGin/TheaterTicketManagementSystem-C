#pragma once

typedef enum {
	PLAY_TYPE_FILE = 1,
	PLAY_TYPE_OPEAR = 2,
	PLAY_TYPE_CONCERT = 3
} play_type_t;//剧目类型定义，1表示电影，2表示歌剧，3表示音乐会

typedef enum {
	PLAY_RATE_CHILD = 1,
	PLAY_RATE_TEENAGE = 2,
	PLAY_RATE_ADULT = 3
} play_rating_t;//演出级别类型定义，1表示儿童可观看，2表示青少年可观看，3表示成人可观看


typedef struct {
	int id; //剧目id
	char name[31]; //剧目名称
	play_type_t type;
	char area[10]; //剧目出品地区
	play_rating_t rating;  //剧目等级
	int duration; //时长  分钟为单位
//	date_t start_date;
//	date_t end_date;
	int price;
}play_t;

typedef struct play_node{
	play_t data;
	struct play_node *next;
	struct play_node *prev;
}PLAY;
