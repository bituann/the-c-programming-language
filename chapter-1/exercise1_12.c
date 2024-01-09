#include <stdio.h>

int main () {
	char c;
	
	while ((c = getchar()) != '}') {
		if (c == ' ' || c == '\t')
			putchar('\n');
		else
			putchar(c);
	}
	
	return 0;
}