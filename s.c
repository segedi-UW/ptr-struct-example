#include <stdio.h>
#include <stdlib.h>

// This is how it would be done
// In a normal setting
/* 
typedef struct mystruct {
	int id;
	char *msg;
} mystruct;
 */

struct mystruct {
	int id;
	char *msg;
};

void useStruct(struct mystruct *mine) {
	printf("We are in useStruct...\n");
	// Note the arrow notation, which makes mine->id equivalent to (*mine).id etc
	printf("(.)  arg struct: id(%d), msg: %s\n", (*mine).id, (*mine).msg);
	printf("(->) arg struct: id(%d), msg: %s\n", mine->id, mine->msg);
}

int main(void) {
	// Now that you have a solid understanding of pointers... Lets talk about structs
	// creating struct on stack
	struct mystruct mine;
	mine.id = 1;
	mine.msg = "This is my struct. There are many like it, but this one is mine.";

	// we can pass it like other variables
	useStruct(&mine);
	typedef struct mystruct mystruct; 	// we can define a type to shorten declarations
										// This is typically done at the declaration of
										// the struct type, but I just wanted to show you
										// how it could be done
	mystruct test;
	test.id = 3;
	test.msg = "Avoided extra typing!";
	useStruct(&test);
}
