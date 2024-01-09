#include <stdio.h>

int main () {
	char c;
	int b, nl, t;
	b = 0;
	nl = 0;
	t = 0;
	
	while ((c = getchar()) != '}') {
		if (c == ' ')
			++b;
		else if (c == '\t')
			++t;
		else if (c == '\n')
			++nl;
	}
	
	printf("Blanks: %d\nTabs: %d\nNew Lines: %d\n", b, t, nl);
	
	return 0;
}