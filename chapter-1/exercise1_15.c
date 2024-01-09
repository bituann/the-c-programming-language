#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float convert (int);

int main () {
	for (int i = LOWER; i <= UPPER; i+=STEP)
		printf("%4d\t%6.2f\n", i, convert(i));
}

float convert(int fahr) {
	return (5.0/9.0) * (fahr - 32);
}