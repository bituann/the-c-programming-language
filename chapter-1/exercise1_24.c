#include <stdio.h>


#define MAXLINE 100000


void checkBasicSyntaxErrors (char text[]);
int checkQuotes (char text[], char quote);
int checkCurlyBraces (char text[]);
int checkParentheses (char text[]);
int checkBrackets (char text[]);
int countCommentChars (char text[], int start);
int increment (int num, int increment);
int decrement (int num, int decrement);
int getCurrentLine (char array[], int limit);


int main ()
{
	char line[MAXLINE];
	
	while ((getCurrentLine(line, MAXLINE)) > 0)
		checkBasicSyntaxErrors(line);
}


void checkBasicSyntaxErrors (char t[])
{
	//initialize variables
	int cS, cD, cC, cP, cB;
	
	//check for single quotes
	cS = checkQuotes(t, '\'');
	//print message
	printf("Single Quote: %d unmatched\n", cS);
	
	//check for double quotes
	cD = checkQuotes(t, '"');
	//print message
	printf("Double Quote: %d unmatched\n", cD);
	
	//check for curly braces
	cC = checkCurlyBraces(t);
	//print message
	printf("Curly Braces: %d unmatched\n", cC);
	
	//check for parentheses
	cP = checkParentheses(t);
	//print message
	printf("Parentheses: %d unmatched\n", cP);
	
	//check for bracket
	cB = checkBrackets(t);
	//print message
	printf("Brackets: %d unmatched\n", cB);
}


int checkQuotes (char t[], char quote)
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
			
		//if char is just quote
		if (t[i] == quote && t[i - 1] != '\\') {
			//increment counter
			count = increment(count, 1);
			i = increment(i, 1);
			
			//loop from there till the next newline char
			while (t[i] != '\n') {
				//if just endquote is found
				if (t[i] == quote && t[i - 1] != '\\') {
					//decrement count
					count = decrement(count, 1);
					
					i = increment(i, 1);
					
					//break
					break;
				}
				i = increment(i, 1);
			}
		}
	}
					
	//return count
	return count;
}


int checkCurlyBraces (char t[])
{
	//initialize variables
	int count = 0;
	
	//initialize loop to go through array
	for (int i = 0; t[i] != '\0'; ++i) {
		//if char is / and next char is / or *
		if (t[i] == '/' && (t[i + 1] == '/' || t[i +1] == '*')) {
			//count comment
			//increment loop counter by that number
			i = increment(i, countCommentChars(t, i) - 1);
			
			//move to the next iteration
			continue;
		}
		
		//if char is just {
		if (t[i] == '{' && t[i - 1] != '\\')
			//increment count
			count = increment(count, 1);
			
		//if char is just }
		if (t[i] == '}' && t[i - 1] != '\\')
			//decrement count
			count = decrement(count, 1);
	}
			
	//return count
	return count;
}


int checkParentheses (char t[])
{
	//initialize variables
	int count = 0;
	
	//initialize loop to go through array
	for (int i = 0; t[i] != '\0'; ++i) {
		//if char is / and next char is / or *
		if (t[i] == '/' && (t[i + 1] == '/' || t[i +1] == '*')) {
			//count comment
			//increment loop counter by that number
			i = increment(i, countCommentChars(t, i) - 1);
			
			//move to the next iteration
			continue;
		}
		
		//if char is just (
		if (t[i] == '(' && t[i - 1] != '\\')
			//increment count
			count = increment(count, 1);
			
		//if char is just )
		if (t[i] == ')' && t[i - 1] != '\\')
			//decrement count
			count = decrement(count, 1);
	}
			
	//return count
	return count;
}


int checkBrackets (char t[])
{
	//initialize variables
	int count = 0;
	
	//initialize loop to go through array
	for (int i = 0; t[i] != '\0'; ++i) {
		//if char is / and next char is / or *
		if (t[i] == '/' && (t[i + 1] == '/' || t[i +1] == '*')) {
			//count comment
			//increment loop counter by that number
			i = increment(i, countCommentChars(t, i) - 1);
			
			//move to the next iteration
			continue;
		}
		
		//if char is just [
		if (t[i] == '[' && t[i - 1] != '\\')
			//increment count
			count = increment(count, 1);
			
		//if char is just ]
		if (t[i] == ']' && t[i - 1] != '\\')
			//decrement count
			count = decrement(count, 1);
	}
			
	//return count
	return count;
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