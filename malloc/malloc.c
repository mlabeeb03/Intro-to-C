#include "../utils/minunit.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Duplicates the input string by dynamically allocating memory for
	the duplicate string using `malloc` and then copying the string
	into the allocated memory. Returns a pointer to the allocated memory.
	You may want to use the string_length function to figure out the
	length of the input string.
*/
char *string_dup(char *src) {
	char *ret = malloc(strlen(src) + 1);
	strcpy(ret, src);
	return ret;
}

/*
	A generic version of string_copy, mem_copy receives a block of memory
	of any type and copies its contents to the destination pointer (dest).
	You may want to cast the input pointers to char pointers first before
	performing the copying. `n` is the amount of data that should be copied
	from `src` to `dest`.
*/
void mem_copy(void *dest, const void *src, int n) { memcpy(dest, src, n); }

/*
	Given a pointer of `malloc`'d memory, this function will
	attempt to resize the allocated memory to the new specified
	size. Any data that was previously in the old `malloc`'d
	memory should be intact in the new resized block of memory.
	Some edge cases to consider: how should resizing be handled
	in the case when old_size < new_size? What about when
	old_size > new_size?

	Do not use the `realloc` function from the standard libary.
*/
void *resize_memory(void *ptr, int old_size, int new_size) {
	char *new_ptr = realloc(ptr, new_size);
	new_ptr[new_size] = '\0';
	return new_ptr;
}

#ifndef TESTING
int main(void) {
	char *url = strdup("http://bloomtech.com");
	char *path = strdup("/students/");
	int url_length = strlen(url);
	int path_length = strlen(path);

	int new_length = url_length + path_length + 1; // +1 for the NUL terminator
	char *new_url = resize_memory(url, url_length, new_length);
	char *p = new_url + url_length;

	while (*path != '\0') {
		*p = *path;
		p++;
		path++;
	}

	*p = '\0';

	char *new_new_url = resize_memory(new_url, new_length, 8);
	printf("%s\n", new_new_url);
	return 0;
}
#endif
