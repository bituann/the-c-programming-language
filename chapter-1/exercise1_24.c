#include <stdio.h>


#define MAXLINE 100000


void checkBasicSyntaxErrors (char text[]);
int checkSingleQuotes (char text[]);
int checkDoubleQuotes (char text[]);
int checkCurlyBraces (char text[]);
int checkParentheses (char text[]);
int checkBrackets (char text[]);
int countCommentChars (char text[], int start);
int increment (int num, int increment);
int decrement (int num, int decrement);
int getCurrentLine (char array[], int limit);


int main ()
{
	
}


void checkBasicSyntaxErrors (char t[])
{
	//initialize variables
	//check for single quotes
	//print message
	//check for double quotes
	//lrint message
	//check for curly braces
	//print message
	//check for parentheses
	//print message
	//check for bracket
	//print message
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
	//initialize variables
	int i, c;
	
	//keep calling getchar() until exit condition is met
	for (i = 0; i < lim - 1 && (c = getchar()) != '~'; ++i)
		//add current char to line
		a[i] = c;

	//add end of line char
	a[i] = '\0';
	
	//return length
	return i;
}