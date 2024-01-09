#include <stdio.h>

int main() {
	int c, alpha, num, sym, ws;
	alpha = num = sym = ws = 0;
	
	while ((c = getchar()) != '\n') {
		if ((c >= 'a' || c >= 'A') && (c <= 'z' || c <= 'Z'))
			++alpha;
		else if (c >= '0' && c <= '9')
			++num;
		else if (c == ' '|| c == '\t' || c == '\n')
			++ws;
		else
			++sym;
	}
	
	printf("\n%11s:", "ALPHABETS");
	for (alpha; alpha > 0; alpha--)
		printf(" |");
		
	printf("\n%11s:", "NUMBERS");
	for (num; num > 0; num--)
		printf(" |");
		
	printf("\n%11s:", "SYMBOLS");
	for (sym; sym > 0; sym--)
		printf(" |");
		
	printf("\n%11s:", "WHITESPACE");
	for (ws; ws > 0; ws--)
		printf(" |");
	
	return 0;
}