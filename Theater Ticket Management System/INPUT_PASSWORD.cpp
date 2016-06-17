#include "stdafx.h"
#include "INPUT_PASSWORD.h"

void INPUT_PASSWORD(char PASSWORD[], int N) {
	char userpassword[100] = "";
	unsigned int key = 1;
	int index_password = 0;
	while (key != 13) {
		key = _getch();
		if (0 == key || 0xe0 == key) key |= _getch() << 8; {

			if (((char)key >= 'A' && (char)key <= 'Z') || ((char)key >= '0' && (char)key <= '9') || ((char)key >= 'a' && (char)key <= 'z') && index_password < 15) {
				putchar('*');
				userpassword[index_password++] = (char)key;
			}
			else if (key == 8)
			{
				printf_s("\b \b");
				index_password--;
			}
		}
	}
	strcpy_s(PASSWORD, N, userpassword);
}
