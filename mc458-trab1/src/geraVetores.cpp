
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>

#define MAX_INT 32767;

void quick(int*, int, int);

void geraBubble(){
	FILE *Bubble_M;

	Bubble_M = fopen("Bubble_M.txt", "wt");
	int *v;

	for (int i = 0; i < 10; i++){
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++){
			v[j] = rand()%MAX_INT;
		}
		quick(v, 0, 99);
		fprintf(Bubble_M, "100");
		for (int j = 0; j < 100; j++){
			fprintf(Bubble_M, ",%d", v[j]);
		}
		fprintf(Bubble_M, ";\n");
		free(v);
	}
	fclose(Bubble_M);
}

void geraAleatorios(){
	FILE *Aleatorios;

	Aleatorios = fopen("Aleatorios.txt", "wt");
	int *v;

	for (int i = 0; i < 50; i++){
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++){
			v[j] = rand()%MAX_INT;
		}
		int s = 20*(i+1);
		fprintf(Aleatorios, "%d", s);
		for (int j = 0; j < s; j++){
			fprintf(Aleatorios, ",%d", v[j]);
		}
		fprintf(Aleatorios, ";\n");
		free(v);
	}
	fclose(Aleatorios);
}
