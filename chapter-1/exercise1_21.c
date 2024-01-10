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
	
}


void entab (char s[], int len, int tabstop)
{
	//search through line
	//if space is encountered, count how many cosequtive blanks exists
	//if blanks > 1
	//determine how many spaces left till tabstop
	//if it's > blanks, add spaces
	//if it's <= blanks, add tabs until it's > blank
	//remove extra spacs in string
	//increment i, colCounter as necessary
}


int countBlanks (char s[], int start)
{
	int count = 0;
	
	for (int start; s[start] == ' '; ++start)
		++count;
		
	return count;
}


void putChar(char character, char s[], int index)
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