#include <stdio.h>

int main () {
	char c;
	
	while ((c = getchar()) != '}') {
		if (c == '\b')
			printf("\\b");
		else if (c == '\t')
			printf("\\t");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
	
	return 0;
}