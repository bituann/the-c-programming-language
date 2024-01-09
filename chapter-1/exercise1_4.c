#include <stdio.h>

int main () {
	float fahr, celcius;
	float lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	celcius = lower;
	
	printf("%6s\t\t%6s\n", "Cel", "Fahr");
	
	while (celcius <= upper) {
		fahr = (9.0/5.0) * celcius + 32;
		printf("%6.0f\t\t%6.2f\n", celcius, fahr);
		celcius += step;
	}
	
	return 0;
}