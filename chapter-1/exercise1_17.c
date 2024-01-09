#include <stdio.h>

#define MAXLENGTH 1000
#define MINLINELENGTH 80

int getcurrentline (char string[], int limit);
void copy (char from[], char to[]);

/* Print lines with more than 80 characters */

int main () {
	int len, num;
	char line[MAXLENGTH];
	char morethan80[MAXLENGTH][MAXLENGTH];
	
	num = 0;
	
	/*Get input line */
	while ((len = getcurrentline(line, MAXLENGTH)) > 0)
		/* Check if line length > minimum, then save if it does */
		if (len > MINLINELENGTH) {
			copy(line, morethan80[num]);
			++num;
		}
	
	/* Print lines longer than minimum length */
	printf("The lines longer than 80 characters are %d:\n", num);
	for (num = num - 1; num >= 0; --num)
		printf(" - %s", morethan80[num]);
		
	return 0;
}

int getcurrentline (char s[], int limit) {
	/* 
		1. Read line from keyboard
		2. Test for end of line
		3. Add line to line array
		4. Increment character counter
		5. Add new line character to array
		6. Increment character counter
		8. Add null character
	 */
	 
	 int c, i;
	 
	 for (i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != '}'; ++i)
	 	s[i] = c;
	 	
	 if (c == '\n') {
	 	s[i] = c;
	 	++i;	
	 }
	 
	 s[i] = '\0';
	 
	 return i;
}

void copy (char from[], char to[]) {
	int i = 0;
	
	while ((to[i] = from[i]) != '\0')
		++i;
}