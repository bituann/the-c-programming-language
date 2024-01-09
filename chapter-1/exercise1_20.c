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
	
}


int detab (char s[], int len, int tabstop)
{
	//check for tab in the line
	// if tab is found
		//determine how many columns left till tabstop
		//make space for the blank characters by shifing the remaining characters
		//add that many blank characters
}


void shiftArrayItems (char a[], int len, int start, int shift)
{
	//move characters to ths right by 'shift'
	for (len; len >=shift, --len)
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