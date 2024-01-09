#include <stdio.h>

int main () {
	char c;
	int count;
	
	count = 0;
	
	while ((c = getchar()) != '}') {
		if (c == ' ')
			++count;
		if (c != ' ' && count >= 1) {
			putchar(' ');
			count = 0;
		}
		if (c != ' ')
			putchar(c);
	}
	
	return 0;
}