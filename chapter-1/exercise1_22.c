#include <stdio.h>


#define MAXLINE 1000
#define MAXCOL 10


void fold (char line[], int len);
void putChar (char character, char array[], int index);
void shiftArrayItems (char array[], int length, int start, int shift);
int increment (int num, int increment);
int decrement (int num, int decrement);
int getCurrentLine (char array[], int limit);


int main
{
	
}


void fold (char s[], int len)
{
	//loop through array
	//keep track of current col, and index of last non-blank char
	//when maxcol is reached
	//shift everything from just after last non-blank char to the right
	//insert new line char
}


void putChar (char character, char a[], int index)
{
	a[index] = character;
}


void shiftArrayItems (char a[], int len, int start, int shift)
{
	for (len; len >= start; --len)
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