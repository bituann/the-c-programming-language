#include <stdio.h>


#define MAXLINE 10000


void removeComments (char text[]);
void countCommentChar (char text[], int start);
void countStringChar (char text[], int start);
void shiftArrayItemsLeft (char array[], int pivot, int shift);
int increment (int num, int increment);
int decrement (int num, int decrement);
int getCurrentLine (char array[], int limit);


int main ()
{
	
}


void removeComments (char s[])
{
	//check through text
	//if char is ", count total string elements, then skip to that index
	//if char is /
		//and next char is /
		//count up to \n and remove those characters
		
		//and next char is *
		//count up to / with * as prev char
		//remove those characters
}