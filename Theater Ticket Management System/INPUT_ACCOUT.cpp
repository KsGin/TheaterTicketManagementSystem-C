#include "stdafx.h"
#include "INPUT_ACCOUT.h"

void INPUT_ACCOUT(char ACCOUT[], int N) {
	char username[100] = "";
	unsigned int key = 1;
	int index_name = 0;
	while (key != 13) {
		key = _getch();
		if (0 == key || 0xe0 == key) key |= _getch() << 8; {

			if (((char)key >= 'A' && (char)key <= 'Z') || ((char)key >= '0' && (char)key <= '9') || ((char)key >= 'a' && (char)key <= 'z') && index_name < 15) {
				putchar((char)key);
				username[index_name++] = (char)key;
			}
			else if (key == 8)
			{
				printf_s("\b \b");
				index_name--;
			}
		}
	}
	strcpy_s(ACCOUT, N, username);
}