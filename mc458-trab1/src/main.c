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

void bubble(int*, int);
void insertion(int*, int);
void merge(int*, int, int);
void quick(int*, int, int);
void heap(int*, int);

void printV(int* v, int n);

int main(void) {

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

	//bubble(v, n);
	//insertion(v, n);
	//merge(v, 0, n - 1);
	//quick(v, 0, n - 1);
	heap(v, n); //não funfando ainda

	printV(v, n);

	return EXIT_SUCCESS;
}

void printV(int* v, int n) {
	int i;
	printf("\nDepois:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
}
