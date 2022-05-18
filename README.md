# ptr-struct-example

This is a very basic introduction to pointers and structs (most assumes I am here instructing while going over code).

# How to Use

First compile the first three sections
```bash
make
```

Then take a look at p.c (i.e. look at the code). After reading the comments and mulling it over, run the program.
By default it only runs the first function - edit the main function to show the rest of the results as you see fit.

To recompile and run `p.c`, or other files using the same format, you can use
```bash
make p
./p
```
or more generally
```bash
make <name>
./<name>
```

After that take a look at `pExercise.c` - you should complete the `mystrlen(const char *str)` method, **only using pointer arithmetic
and your own loop** - try to use a custom for loop.

When your done compile and run `pExercise.c`.
I have a very rudimentary test setup to make sure you get the right results that compares `mystrlen()` output with `strlen()`.

Do the same thing with the s activities. You should know that sExercises.c will not compile until you fix the typedef for `mystruct`.

## Notes
* Please note that while pointers and arrays are very similar they [are not the same](http://c-faq.com/aryptr/aryptr2.html). 
One thing to keep in mind is that a C array that is passed into a function
[*decays* into a pointer](http://c-faq.com/aryptr/aryptrparam.html), essentially simulating pass by reference. In other words,

```C
void move(char[] a);
```
becomes
```C
void move(char *a);
```
at compile-time and beyond.

* Pointer arithmetic implicitly mutiplies by the size of the Type. (void*) will always be modifed by 1.
