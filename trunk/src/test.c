#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main (int args, char **argv)
{
	char* s = "abc";
	append_str(&s);
	printf("Hello, string: %s\n", s);
	return 0;
}

void append_str( char* s ) 
{
	size_t size = 0;
	strcat(s, "def");
}
