#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NAME_LENGTH

// TODO First you should typedef declare this struct. NOTE This program not compile untill you do!
struct Person {
	int age;
	char name[NAME_LENGTH];
};

Person * init_Person(int age, char *name) {
	// TODO Fill in this method to create and return a Person on the heap
	return NULL;
}

void check(Person *p) {
	if (p == NULL) {
		printf("ERROR: The person was null!");
		exit(0);
	}
	printf("P: age(%d), name(%s)\n", p->age, p->name);
}

int main(void) {
	Person *p = init_Person(7, "Antonio");
	check(p);
	Person *p2 = init_Person(7, "Indigo Montoya"); // BUFFER OVERFLOW!
	check(p2);
}
