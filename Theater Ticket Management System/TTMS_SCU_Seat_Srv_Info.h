#pragma once
typedef enum {
	SEAT_NODE = 0,
	SEAT_GOOD = 1,
	SEAT_BROKEN = 9
}SEAT_STATUS;

typedef struct {
	int id;
	int RoomID;
	int row;
	int col;
	SEAT_STATUS status;
}seat_t;


typedef struct seat_node {
	seat_t data;
	struct  seat_node *node_next;
	struct  seat_node *node_prev;
}SEAT;