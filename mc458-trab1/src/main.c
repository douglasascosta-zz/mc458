/*
 ============================================================================
 Name        : mc458-trab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(int*, int);
void insertion(int*, int);
void merge(int*, int, int);
void quick(int*, int, int);
void heap(int*, int);

void printV(int* v, int n);

int main(int argc, const char* argv[]) {

	int n = 10;
	int i;

	int* v = (int*) malloc((n + 1) * sizeof(int));

	printf("Antes:\n");
	for (i = 0; i < n; i++) {
		// artificio para gerar numeros entre 0 e 1000
		// RAND_MAX e uma constante definida na biblioteca stdlib.h
		// e que indica o maximo valor retornado por rand()
		v[i] = rand() % 100;
		printf("%d ", v[i]);
	}

	if (strcmp(argv[1], "-b") == 0) {
		printf("\nBubble:\n");
		bubble(v, n);
	}
	if (strcmp(argv[1], "-i") == 0) {
		printf("\nInsertion:\n");
		insertion(v, n);
	}
	if (strcmp(argv[1], "-m") == 0) {
		printf("\nMerge:\n");
		merge(v, 0, n - 1);
	}
	if (strcmp(argv[1], "-q") == 0) {
		printf("\nQuick:\n");
		quick(v, 0, n - 1);
	}
	if (strcmp(argv[1], "-h") == 0) {
		printf("\nHeap:\n");
		heap(v, n);
	}

	printV(v, n);

	return EXIT_SUCCESS;
}

void printV(int* v, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
}
