#include <stdio.h>


#define MAXLINE 10000


void removeComments (char text[], int length);
int countCommentChar (char text[], int start);
int countStringChar (char text[], int start);
void shiftArrayItemsLeft (char array[], int len, int pivot, int shift);
int increment (int num, int increment);
int decrement (int num, int decrement);
int getCurrentLine (char array[], int limit);


int main ()
{
	
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
			strCount = countStringChar(s, i + 1);
			i = increment(i, strCount);
			//to offset the addition done as the iteration changes
			i = decrement(i, 1);
			continue;
		}
		
		//if char is /
		if (s[i] == '/' && (s[i + 1] == '/' || s[i +1] == '*')) {
		//and next char is /
		//count up to \n and remove those characters
		commCount = countCommentChar(s, i);
		//and next char is *
		//count up to / with * as prev char
		//remove those characters
		shiftArrayItemsLeft(s, len, i, commCount);
		//to offset the addition done as the iteration changes
		i = decrement(i, 1);
		}
	}
}


int countCommentChar (char t[], int start)
{
	int count;
	count = 0;
	
	if (t[start + 1] == '/') {
		while (t[start] != '\n') {
			++count;
			++start;
		}
		if (t[start] == '\n')
			++count;
			
		return count;
	}
	
	if (t[start + 1] == '*') {
		while (t[start] != '/' && t[start - 1] != '*') {
			++count;
			++start;
		}
		if (t[start + 1] == '\n')
			++count;
			
		return count;
	}
}


int countStringChar (char t[], int start)
{
	int count = 1;
	++start;
	
	while (t[start] != '"') {
		if (t[start - 1] == '\\')
			++count;
			++start;
			continue;
			
		++count;
		++start;
	}
	
	++count;
	
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
	
	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != '}'; ++i)
		a[i] = c;
		
	if (c == '\n') {
		a[i] = c;
		++i;
	}
	
	a[i] = '\0';
	
	return i;
}