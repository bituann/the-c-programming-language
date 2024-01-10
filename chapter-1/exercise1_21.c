#include <stdio.h>


#define MAXLINE 1000
#define TABSTOP 8


void entab (char string[], int length, int tabstop);
int countBlanks (char line[], int start);
void putChar (char character, char string[], int index);
void removeArrayItem (char array[], int index);
int increment (int num, int increment);
int decrement (int num, int decrement);
int getCurrentLine (char array[], int limit);


int main ()
{
	int len;
	char line[MAXLINE];
	
	while((len = getCurrentLine(line, MAXLINE)) > 0) {
		entab(line, len, TABSTOP);
		printf("here\n");
		printf("%s", line);
	}
}


void entab (char s[], int len, int tabstop)
{
	//Variables
	int colCounter, colTillTabstop, blankCounter;
	colCounter = colTillTabstop = blankCounter = 0;
	
	//search through line
	for (int i = 0; s[i]; ++i) {
		//column counter logic
		if (colCounter >= 8)
			colCounter = 0;
			
		
		if (s[i] != ' ') {
			colCounter = increment(colCounter, 1);
			continue;
		}
			
		//if space is encountered, count how many consequtive blanks exists
		blankCounter = countBlanks(s, i);
		
		if (blankCounter == 1) {
			colCounter = increment(colCounter, 1);
			continue;
		}
			
		//if blanks > 1
		//determine how many spaces left till tabstop
		colTillTabstop = tabstop - colCounter;
		
		//if it's <= blanks, add tabs until it is > blank
		while (colTillTabstop <= blankCounter){
			putChar('\t', s, i);
			i = increment(i, 1);
			colCounter = 0;
			colTillTabstop = tabstop - colCounter;
			blankCounter = decrement(blankCounter, colCounter);
		}
		
		//if it's > blanks, add spaces
		while (blankCounter) {
			putChar(' ', s, i);
			i = increment(i, 1);
			blankCounter = decrement(blankCounter, 1);
			if (colCounter >= 8)
				colCounter = 0;
			colCounter = increment(colCounter, 1);
		}
		
		//remove extra spaces in string
		for (int j = i; s[j] == ' '; ++j)
			removeArrayItem(s, j);
	}
}


int countBlanks (char s[], int start)
{
	int count = 0;
	
	for (int i = start; s[i] == ' '; ++i)
		++count;
		
	return count;
}


void putChar (char character, char s[], int index)
{
	s[index] = character;
}

void removeArrayItem (char a[], int index)
{
	while (a[index]) {
		a[index] = a[index + 1];
		++index;
	}
	
	a[index] = a[index + 1];
}


int increment (int num, int increment)
{
	return num += increment;
}


int decrement (int num, int decrement)
{
	return num -= decrement;
}

int getCurrentLine (char s[], int lim)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != '}'; ++i)
		s[i] = c;
		
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	
	return i;
}