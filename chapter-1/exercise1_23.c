#include <stdio.h>


#define MAXLINE 5000000


void removeComments (char text[], int length);
int countCommentChar (char text[], int start);
int countStringChar (char text[], int start);
void shiftArrayItemsLeft (char array[], int len, int pivot, int shift);
int increment (int num, int increment);
int decrement (int num, int decrement);
int getCurrentLine (char array[], int limit);


int main ()
{
	int len;
	char line[MAXLINE];
	
	while ((len = getCurrentLine(line, MAXLINE)) > 0) {
		removeComments(line, len);
		printf("%s", line);
	}
}


void removeComments (char s[], int len)
{
	//Variables
	int commCount, strCount;
	commCount = strCount = 0;
	
	//check through text
	for (int i = 0; s[i]; ++i) {
		//if char is ", count total string elements, then skip to that index
		if (s[i] == '"' || s[i] == '\'') {
			//count the characters in the string
			strCount = countStringChar(s, i);
			i = increment(i, strCount);
			
			//to offset the addition done as the iteration changes
			i = decrement(i, 1);
			continue;
		}
		
		//if char is /
		//confirm it's a comment
		if (s[i] == '/' && (s[i + 1] == '/' || s[i +1] == '*')) {
			//count the characters
			commCount = countCommentChar(s, i);
		
			//remove those characters
			shiftArrayItemsLeft(s, len, i, commCount);
			
		/* to offset the addition done as the iteration changes
		 so that the char that replaced the start of the comment
		can be checked too */
		i = decrement(i, 1);
		}
	}
}


int countCommentChar (char t[], int start)
{
	int count;
	count = 0;
	
	//for single line comments
	if (t[start + 1] == '/') {
		while (t[start] != '\n') {
			++count;
			++start;
		}
			
		return count;
	}
	
	//for multi-line comments
	if (t[start + 1] == '*') {
		//check for format */ at the end of comment
		// also handles */*, even though the compiler would flag a comment that has that
		while (!(t[start] == '/' && t[start - 1] == '*' && t[start + 1] != '*')) {
			++count;
			++start;
		}
		
		//takes care of any excess /s immediately after the comment end
		if (t[start] == '/')
			while (t[start] != '\n') {
				++count;
				++start;
			}
			
		return count;
	}
}


int countStringChar (char t[], int start)
{
	int count = 0;
	
	//for single quotes (character constants)
	if (t[start] == '\'') {
		++count;
		
		/* ensures it doesn't mistake the escape sequence
		for single quotes as the end of the string.
		It also handles the situation where the escape
		sequence for \ is just before the end of quote */
		for (int i = start + 1;
				!(t[i] == '\'' && (t[i - 1] != '\\' || t[i - 2] == '\\'));
				++i)
			++count;
			
		++count;
	}
	
	//for double quotes (string constants)
	else if (t[start] == '"') {
		++count;
		
		/* ensures it doesn't mistake the escape sequence
		for double quotes as the end of the string.
		It also handles the situation where the escape
		sequence for \ is just before the end of quote */
		for (int i = start + 1;
				!(t[i] == '"' && (t[i - 1] != '\\' || t[i - 2] == '\\'));
				++i)
			++count;
			
		++count;
	}
	
	return count;
}


void shiftArrayItemsLeft (char a[], int len, int start, int shift)
{
	for (start; len >= start; ++start)
		a[start] = a[start + shift];
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
	
	for (i = 0; i < lim - 1 && (c = getchar()) != '~'; ++i)
		a[i] = c;
		
	if (c == '\n') {
		a[i] = c;
		++i;
	}
	
	a[i] = '\0';
	
	return i;
}