#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

/*
	Given a character array s (as a pointer), return the number of
	characters in the string.

	Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s) {
	if (s == NULL)
		return 0;
	int res = -1;
	while (s[++res] != '\0')
		;
	return res;
}

/*
	Write a function that reverses the order of string s and outputs
	the reversed string to the input array rv. The rv array will have
	enough space for the reversed string. Don't forget to terminate
	the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s) {
	int ind = 0;
	int len = string_length(s);
	for (int i = len - 1; i >= 0; i--) {
		rv[ind++] = s[i];
	}
	rv[ind] = '\0';
	return rv;
}

#ifndef TESTING
int main(void) {
	char quote1[] = "Don't forget to be awesome";
	char quote2[] = "a man a plan a canal panama";
	char quote3[] = "";

	char rv[512];

	printf("The string 'Don't forget to be awesome' has %d characters.\n",
		   string_length(quote1));
	printf("The string 'a man a plan a canal panama' reversed is: '%s'\n",
		   reverse_string(rv, quote2));

	printf("The string '\"\"' has %d characters.\n", string_length(quote3));

	return 0;
}
#endif
