#include <stdio.h>

#define MAXLINE 100

void reverse (char string[]);
int getcurrentline(char line[], int limit);
void copy (char from[], char to[]);

int main ()
{
	int num, len;
	char line[MAXLINE];
	char allLines[MAXLINE][MAXLINE];
	
	num = 0;
	
	while (getcurrentline(line, MAXLINE)) {
		copy(line, allLines[num]);
		++num;
	}
	
	printf("The lines in reverse are:\n");
	
	// Print all lines in reverse
	for (int i = 0; i < num; ++i) {
		reverse(allLines[i]);
		printf("%s", allLines[i]);
	}
}

void reverse (char s[])
{
	// Count number of characters in string
	int count;
	char reverse[count - 1];
	
	count = 0;

	while (s[count] != '\0')
		++count;
		
	// Reverse string by swapping
	int j = count - 1;
	
	for (int i = 0; i <= j ; ++i) {
		char temp;
		
		if (s[j] == '\n'){
			--j;
			--i;
		}
		else {
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			 --j;
		}
	}
}

int getcurrentline (char s[], int limit)
{
	int i, c;
	
	for (i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != '}'; ++i)
		s[i] = c;
		
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
		
	return i;
}

void copy (char from[], char to[])
{
	int i;
	
	i = 0;
	
	while ((to[i] = from[i]) != '\0')
		++i;
}