#include <stdio.h>

#define IN 0
#define OUT 1
#define MAX 10

int main () {
	char c;
	int count[MAX];
	int counter, state;
	int sum;
	
	state = IN;
	counter = 0;
	sum = 0;
	
	for (int i = 0; i < MAX; i++)
		count[i] = 0;
	
	while ((c = getchar()) != '\n') {
		if (c == ' ' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++counter;
			++count[counter];
		}
		else
			++count[counter];
	}
	
	for (int i = 0; i < MAX; i++)
		sum += count[i];
		
	while (sum > 0) {
		for (int i = 0; i < MAX; i++) {
			if (count[i] <= 0) 
				printf("    ");
			else {
				printf("--  ");
				--count[i];
				--sum;
			}
		}
		printf("\n");
	}
	
	return 0;
}