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


int checkSingleQuotes (char t[])
{
	//initialize variables
	int count = 0;
	
	//initialize loop to go over array
	for (int i = 0; t[i] != '\0'; ++i) {
		//if char is / and next char is / or *
		if (t[i] == '/' && (t[i + 1] == '/' || t[i +1] == '*')) {
			//count comment
			//increment loop counter by that number
			i = increment(i, countCommentChars(t, i) - 1);
			
			//move to the next iteration
			continue;
		}
			
		//if char is just '
		if (t[i] == '\'' && t[i - 1] != '\\') {
			//increment counter
			count = increment(count, 1);
			
			//loop from there till the next newline char
			while (t[i] != '\n')
				//if just ' is found
				if (t[i] == '\'' && t[i - 1] != '\\') {
					//decrement count
					count = decrement(count, 1);
					
					i = increment(i, 1);
					
					//break
					break;
				}
				i = increment(i, 1);
		}
	}
					
	//return count
	return count;
}


int checkDoubleQuotes (char t[])
{
	//initialize variables
	int count = 0;
	
	//initialize loop to go over array
	for (int i = 0; t[i] != '\0'; ++i) {
		//if char is / and next char is / or *
		if (t[i] == '/' && (t[i + 1] == '/' || t[i +1] == '*')) {
			//count comment
			//increment loop counter by that number
			i = increment(i, countCommentChars(t, i) - 1);
			
			//move to the next iteration
			continue;
		}
			
		//if char is just "
		if (t[i] == '"' && t[i - 1] != '\\') {
			//increment counter
			count = increment(count, 1);
			
			//loop from there till the next newline char
			while (t[i] != '\n')
				//if just " is found
				if (t[i] == '"' && t[i - 1] != '\\') {
					//decrement count
					count = decrement(count, 1);
					
					i = increment(i, 1);
					
					//break
					break;
				}
				i = increment(i, 1);
		}
	}
					
	//return count
	return count;
}


int countCurlyBraces (char t[])
{
	//initialize variables
	//initialize loop to go through array
		//if char is just {
			//increment count
		//if char is just }
			//decrement count
			
	//return count
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