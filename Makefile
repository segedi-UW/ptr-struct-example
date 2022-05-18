CFLAGS=-g -Wall

compile : p s

p : p.c
	gcc -o p p.c $(CFLAGS)

s : s.c
	gcc -o s s.c $(CFLAGS)

pExercises : pExercises.c
	gcc -o pExercises pExercises.c $(CFLAGS)

sExercises : sExercises.c
	gcc -o sExercises sExercises.c $(CFLAGS)
