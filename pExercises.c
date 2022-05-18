#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Your job is to create a strlen function.
 * I want you to use pointer arithmatic/
 * increment the pointer to determine
 * how long it is. You can use a while
 * or for loop, but I will give you
 * all the brownie points for using a for
 * loop.
 */
size_t mystrlen(const char *str) {
	// FIXME
	return 0;
}

void checkEqual(char *msg) {
	int len = strlen(msg);
	int mylen = mystrlen(msg);
	if (len != mylen) {
		printf("Test Failed:\n");
		printf("Expected: %d, actual: %d for string:\n'%s'\n", len, mylen, msg);
		exit(0);
	}
}

int main(void) {
	// Do not modify this code. It is simply test code
	
	checkEqual("Hey there!");
	checkEqual("NOOOOOO\n\n!");
	checkEqual("!\0Huh?!");

	printf("Passed all tests!");
	return 0;
}
