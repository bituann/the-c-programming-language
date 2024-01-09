#include <stdio.h>

#define MAXLINE 10 /* maximum input line length */

int ggetline (char line[], int maxline);
void copy(char to[], char from[]); 

/* print the longest input line */
  
int main() {
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	
	max = 0; 
	while ((len = ggetline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len; 
			copy(longest, line);
		}
		
	if (max > 0) /* there was a line */
		printf("Longest Line: %s\n", longest);
		printf("Length: %d", max);
		
	return 0; 
}
 
 /* getline: read a line into s, return length */
int ggetline (char s[], int lim) {
	int c, i;
 	
	for (i = 0; (c=getchar()) != '\n' && c != '}'; ++i)
		/*Add char in c to array if array isn't full */
		if (i < lim - 1)
			s[i] = c;
			
		/* Add null character if array is already full */
		else if (i == lim - 1)
			s[i] = '\0';

	if (c == '\n') {
		/* Add character if array isn't full */
		if (i < lim - 1)
			s[i] = c;
		
		/*Add null character to array if array is already full */
		else if (i == lim - 1)
			s[i] = '\0';
		++i;
	}
	
	/*Add null character if line length <= array length - 1 */
	if (i <= lim - 1)
		s[i] = '\0';

	return i; 
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy (char to[], char from[]) {
	int i;
	i = 0;
	
	while ((to[i] = from[i]) != '\0')
		++i; 
 }