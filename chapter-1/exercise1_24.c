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
	//print message
	//check for curly braces
	//print message
	//check for parentheses
	//print message
	//check for bracket
	//print message
}


int countCommentChars (char t[], int start)
{
	//initialize count variable
	int count = 0;
	
	//for single line comment
	if (t[start + 1] == '/') {
		//loop from given index till next newline char
		for (start; t[start] != '\n'; ++start)
			//update counter
			++count;
			
		//return counter
		return count;
	}
	
	//for multi-line comment
	if (t[start + 1] == '*') {
		//loop from given index till end of comment
		for (start; (!t[start] == '/' && t[start - 1] == '*' && t[start + 1] != '*'); ++start)
			//update counter
			++count;
		
			//update counter for last /
			++count;
	
			//return counter
			return count;
	}
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