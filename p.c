#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PAD 20

void printPointer(void *ptr, const char *msg) {
	printf("%*s: %p\n", PAD, msg, ptr);
}

void arrayExample(void) {
	// An array is nearly identical to a pointer, a pointer to a block of memory that is reserved for the array.
	// These blocks are the size of the Type of the array * the number of elements. For example,
	// an int array[] of length 5 would take up a block of 20 bytes, assuming an int is 4 bytes long.
	// On the other hand, a char array[] of length 5 would only take up 5 bytes, assuming a char is 1 byte
	// long.
	
	int intArray[5];
	char charArray[5];
	printf("Sizeof  intArray: %ld\n", sizeof(intArray)); 	// likely to be 20 bytes
	printf("Sizeof charArray: %ld\n", sizeof(charArray));	// likely to be 5 bytes

	// You can think of Arrays as const pointers with reserved memory.
	// We cannot increment an Array directly like before,
	// but we can set pointers equal to the address and
	// increment them.
	
	char *charPointer = charArray;
	printPointer(charPointer, "charPointerOfArray");
	charPointer++;
	printPointer(charPointer, "charPointerOfArray++");
	printf("\n\n");

	int *intPointer = intArray;
	printPointer(intPointer, "intPointerOfArray");
	intPointer++;
	printPointer(intPointer, "intPointerOfArray++");
	printf("\n\n");
}

void pointerExample(void) {
	char *p = NULL;
	// 'p' still exists on the stack here, even though it points to NULL
	printf("Addr: (%p); Note that the address is not null, when the value is: %p\n", &p, p); // %p is for address print outs (pointer)

	p = "Hello There!";
	// we can increment p's pointer to move it along
	int len = strlen(p);
	for (int i = 0; i < len; i++, p++) { // NOTE the 'p++', which increments the pointer
		printf(": %c\n", *p); // Remember this is how we defreference
	}
	// we can also reset the pointer completely! Alternatively we make a copy in the beginning, and just recopy it.
	p -= len;
	printf("reset to: (%c)\n", *p);
}

void pointerBasics() {
	// A pointer is just a memory address. We can follow that address
	// to access what it points to.

	char *charPointer; 	// allocation of a pointer is done by specifying
						// it is a pointer 'type' using the asterisk. A type
						// is created when we allocate a variable using
						// a keyword such as char, int, long, etc.
	charPointer = "I am what is pointed to";

	// We can change the address of a pointer by using
	// standard arithmetic operations. C is smart -
	// it automatically modifies a pointer with 
	// respect to the size of its Type.
	
	// As a side note, you can see that the string
	// literals are stored in Read Only mem by
	// noticing that the address of the charPointer
	// is much higher than the stack allocated
	// intValue below
	printf("SizeOf char: %ld\n", sizeof(char));
	printPointer(charPointer, "charPointer");
	charPointer++;
	printPointer(charPointer, "charPointer++");
	printf("Note that the charPointer incremented by 1\n\n");

	int intValue = 6;
	int *intPointer = &intValue;

	printf("SizeOf int: %ld\n", sizeof(int));
	printPointer(intPointer, "intPointer");
	intPointer++;
	printPointer(intPointer, "intPointer++");
	printf("Note that the intPointer incremented by 4, even though we only did intPointer++\n\n");

	intPointer--;
	printf("We can override this behavior by casting the intPointer to a different type! Note I reset the intPointer\n");
	void *intAsVoidPointer = (void*)intPointer;
	printPointer(intAsVoidPointer, "intAsVoidPointer");
	intAsVoidPointer++;
	printPointer(intAsVoidPointer, "intAsVoidPointer++");
	printf("Note that the (void*) casted intPointer now increments by 1. This is the same functionality as a char pointer\n");
	printf("However, (void*) is the generic pointer type that can be casted from and to any other type!\n\n");
}

int main(void) {
	//pointerBasics();
	//pointerExample();
	arrayExample();

	return EXIT_SUCCESS;
}
