#include <stdio.h>

/*
	Given a character pointer x (that points to an array of chars), and a
	character pointer y, copies the character contents of y over to x. Pointer
	arithmetic is necessary here. Also, make sure x points to a null terminator
	at its end to terminate it properly.

	Example call:

	char buffer[1024];

	string_copy(buffer, "Hello!");
	printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y) {
	int ind = 0;
	while (*y != '\0') {
		x[ind++] = *y;
		y++;
	}
	x[ind] = '\0';
}

/*
	Searches the input string `str` for the first instance of the
	character `c` (an unsigned char). This function returns a pointer
	that points to the first instance of the character `c` in the
	input string `str`.

	Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c) {

	while (*str != '\0') {
		if (*str == c) {
			char *p = str;
			return p;
		}
		str++;
	}
	return NULL;
}

/*
	Searches the input string `haystack` for the first instance of
	the string `needle`. This function returns a pointer that points
	to the first instance of the string `needle` in the input
	string `haystack`.

	Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle) {
	while (*haystack != '\0') {
		char *hay = haystack;
		char *ned = needle;
		while (*hay == *ned) {
			hay++;
			ned++;
			if (*ned == '\0') {
				return haystack;
			}
		}
		haystack++;
	}
	return NULL;
}

#ifndef TESTING
int main(void) {
	char *found_char = find_char("hello", 'e');
	char *found_string = find_string("world", "or");

	printf("Found char: %s\n", found_char);
	printf("Found string: %s\n", found_string);

	char *string = "hello, world";
	char empty[20];

	string_copy(empty, string);
	printf("%s\n", empty);

	return 0;
}
#endif
