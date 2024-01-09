#include <stdio.h>

int main () {
	float fahr, celcius;
	float lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	
	printf("%6s\t\t%6s\n", "Fahr", "Cel");
	
	while (fahr <= upper) {
		celcius = (5.0/9.0) * (fahr - 32);
		printf("%6.0f\t\t%6.2f\n", fahr, celcius);
		fahr += step;
	}
	
	return 0;
}