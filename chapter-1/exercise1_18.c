#include <stdio.h>

#define MAXLINE 100

int getCurrentLine (char line[], int limit);
void copy (char from[], char to[]);
void removeTrailingBlanks (char line[], int length);

int main ()
{
	// Get input
	int len;
	int num;
	char line[MAXLINE];
	char allLines[MAXLINE][MAXLINE];
	
	num = 0;
	
	while ((len = getCurrentLine(line, MAXLINE)) > 0) {
		// Remove trailing blanks
		removeTrailingBlanks(line, len);
		
		// Store them
		copy(line, allLines[num]);
		++num;
	}
	
	// Print them
	printf("The fixed lines are:\n");
	for (int i = 0; i < num; ++i)
		printf("%s", allLines[i]);
		
	return 0;
}

int getCurrentLine (char s[], int limit)
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
	int i = 0;
	
	while ((to[i] = from[i]) != '\0')
		++i;
}

void removeTrailingBlanks (char s[], int len)
{
	// Identify location of newline character
	int index = len - 1;
	
	// Replace any blank character existing in nl position with nl
	if (s[index] == ' ' || s[index] == '\t')
		s[index] = '\n';
	
	// Starting with the position before nl, work backwards
	if (s[index] == '\n') {
		/*
			We want to stop as soon as we encounter a non-blank
			character, so the exit condotion for the loop is
			encountering a non-blank character, or when the loop
			reaches the first element (in the case of all blanks)
		*/
		for (int i = index - 1; s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || i == 0; --i) {
			//To delete a line with all blanks
			if (i == 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
				s[i] = '\0';
			/*
				To progressively move nl and null backwards
				over the blanks
			*/
			if (s[i] == ' ' || s[i] == '\t' ) {
				s[i] = '\n';
				s[i + 1] = '\0';
			}		
		}	
	}
}