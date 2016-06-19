#include "stdafx.h"
#include "GET_KEY.h"

char* GET_KEY() { // 获得上下左右	esc 退格 enter等特殊键位 数字字母请使用getch
	unsigned int key;
	key = _getch();
	if (0 == key || 0xe0 == key) key |= _getch() << 8; {
		switch (key)
		{
		case 8: return "Backspace"; break;
		case 9: return "Tab"; break;
		case 13:return "Enter"; break;
		case 27:return "Esc"; break;
		case 18656:return "Up"; break;
		case 20704:return "Down"; break;
		case 19424:return "Left"; break;
		case 19936:return "Right"; break;
		default: return nullptr;
			break;
		}
	}
	return nullptr;
}