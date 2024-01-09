#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main () {
	int fahr;
	
	printf("%6s\t\t%6s\n", "Cel", "Fahr");
	
	for (fahr = UPPER; fahr >= LOWER; fahr-=STEP) {
		printf("%6d\t\t%6.2f\n", fahr, (5.0/9.0) * (fahr - 32));
	}
	
	
	return 0;
}