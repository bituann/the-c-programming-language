#include <stdio.h>


#define MAXLINE 1000
#define TABSTOP 8


void detab (char string[], int len, int tabstop);
void shiftArrayItems (char array[], int len, int start, int shift);
void putChar (char line[], char character, int index);
int increment (int number, int increment);
int decrement (int number, int decrement);
int getCurrentLine (char line[], int limit);


int main ()
{
	int len;
	char line[MAXLINE];
	
	while ((len = getCurrentLine(line, MAXLINE)) > 0) {
		detab(line, len, TABSTOP);
		printf("%s", line);
	}
}


void detab (char s[], int len, int tabstop)
{
	//Variables
	int colCounter, colTillTabstop;
	colCounter = colTillTabstop = 0;
	
	//check for tab in the line
	for (int i = 0; s[i] != '\0'; ++i) {
		// logic for keeping track of columns
		if (colCounter > tabstop)
			colCounter = 0;
			
		colCounter = increment(colCounter, 1);
		
		if (s[i] != '\t')
			continue;
			
		//if tab is found
		//determine how many columns left till tabstop
		colTillTabstop = tabstop - colCounter;
		
		//make space for the blank characters by shifing the remaining characters
		shiftArrayItems(s, len, i, colTillTabstop);
		
		//add that many blank characters
		for (int j = 0; j < colTillTabstop; ++j)
			putChar(s, 'a', i + j);
	}
}


void shiftArrayItems (char a[], int len, int start, int shift)
{
	//move characters to ths right by 'shift'
	for (len; len > start, --len)
		a[len + shift] = a[len];
}


void putChar (char s[], char character, int index)
{
	s[index] = character;
}


int increment (int num, int increment)
{
	return num += increment;
}


int decrement (int num, int decrement)
{
	return num -= decrement;
}

int getCurrentLine (char a[], int limit)
{
	int i, c;
	
	for (i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != '}'; ++i)
		a[i] = c;
		
	if (c == '\n') {
		a[i] = c;
		++i;
	}
	
	a[i] = '\0';
	
	return i;
}