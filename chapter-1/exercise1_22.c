#include <stdio.h>


#define MAXLINE 1000
#define MAXCOL 25


void fold (char line[], int len, int maxCol);
void putChar (char character, char array[], int index);
void shiftArrayItems (char array[], int length, int start, int shift);
int increment (int num, int increment);
int decrement (int num, int decrement);
int getCurrentLine (char array[], int limit);


int main ()
{
	int len;
	char line[MAXLINE];
	
	while ((len = getCurrentLine(line, MAXLINE)) > 0) {
		fold(line, len, MAXCOL);
		printf("%s", line);
	}
}


void fold (char s[], int len, int maxCol)
{
	//Variables
	int colCounter, lastNBcharIndex;
	colCounter = 0;
	
	//loop through array
	for (int i = 0; s[i]; ++i) {
		//keep track of current col
		colCounter = increment(colCounter, 1);
		
		//keep track of index of last non-blank char
		if ((s[i] != ' ' || s[i] != '\t') && (colCounter % maxCol) != 0)
			lastNBcharIndex = i;
			
		if ((colCounter % maxCol) != 0)
			continue;
			
		//when maxcol is reached
		//shift everything from just after last non-blank char to the right
		shiftArrayItems(s, len, lastNBcharIndex, 1);
		len = increment(len, 1);
	
		//insert new line char
		putChar('\n', s, lastNBcharIndex + 1);
	}
}


void putChar (char character, char a[], int index)
{
	a[index] = character;
}


void shiftArrayItems (char a[], int len, int start, int shift)
{
	for (len; len > start; --len)
		a[len + shift] = a[len];
}


int increment (int num, int increment)
{
	return num += increment;
}


int decrement (int num, int decrement)
{
	return num -= decrement;
}


int getCurrentLine (char a[], int lim)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != '}'; ++i)
		a[i] = c;
		
	if (c == '\n') {
		a[i] = c;
		++i;
	}
	
	a[i] = '\0';
	
	return i;
}