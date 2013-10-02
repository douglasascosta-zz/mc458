#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>

#define MAX_INT 32767;

void quick(int*, int, int);

void bubbleInverso(int *v, int n) {
	int i;
	int j;
	int aux;
	int k = n - 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			if (v[j] < v[j + 1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
		k--;
	}
}

void geraBubble() {
	FILE *Bubble;

	Bubble = fopen("Bubble_M.txt", "wt");
	int *v;

	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT
			;
		}
		quick(v, 0, 99);
		fprintf(Bubble, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Bubble, ",%d", v[j]);
		}
		fprintf(Bubble, ";\n");
		free(v);
	}
	fclose(Bubble);

	Bubble = fopen("Bubble_P.txt", "wt");
	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT
			;
		}
		bubbleInverso(v, 100);
		fprintf(Bubble, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Bubble, ",%d", v[j]);
		}
		fprintf(Bubble, ";\n");
		free(v);
	}
	fclose(Bubble);
}

void geraInsertion() {
	FILE *Insertion;

	Insertion = fopen("Insertion_M.txt", "wt");
	int *v;

	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT
			;
		}
		quick(v, 0, 99);
		fprintf(Insertion, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Insertion, ",%d", v[j]);
		}
		fprintf(Insertion, ";\n");
		free(v);
	}
	fclose(Insertion);

	Insertion = fopen("Insertion_P.txt", "wt");
	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT
			;
		}
		bubbleInverso(v, 100);
		fprintf(Insertion, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Insertion, ",%d", v[j]);
		}
		fprintf(Insertion, ";\n");
		free(v);
	}
	fclose(Insertion);
}

void geraMerge() {
	FILE *Merge;

	Merge = fopen("Merge_M.txt", "wt");
	int *v;

	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT;
		}
		quick(v, 0, 99);
		fprintf(Merge, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Merge, ",%d", v[j]);
		}
		fprintf(Merge, ";\n");
		free(v);
	}
	fclose(Merge);

	Merge = fopen("Merge_P.txt", "wt");
	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = 1*(j*i+1)+100*(j*i+1)*(j%2);
		}
		fprintf(Merge, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Merge, ",%d", v[j]);
		}
		fprintf(Merge, ";\n");
		free(v);
	}
	fclose(Merge);
}

void geraAleatorios() {
	FILE *Aleatorios;

	Aleatorios = fopen("Aleatorios.txt", "wt");
	int *v;

	for (int i = 0; i < 50; i++) {
		int s = 20 * (i + 1);
		v = (int*) malloc(s * sizeof(int));
		for (int j = 0; j < s; j++) {
			v[j] = rand() % MAX_INT
			;
		}
		fprintf(Aleatorios, "%d", s);
		for (int j = 0; j < s; j++) {
			fprintf(Aleatorios, ",%d", v[j]);
		}
		fprintf(Aleatorios, ";\n");
		free(v);
	}
	fclose(Aleatorios);
}

void geraQuick() {
	FILE *Quick;

	Quick = fopen("Quick_M.txt", "wt");
	int *v;

	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT;
		}
		fprintf(Quick, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Quick, ",%d", v[j]);
		}
		fprintf(Quick, ";\n");
		free(v);
	}
	fclose(Quick);

	Quick = fopen("Quick_P.txt", "wt");
	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT
			;
		}
		bubbleInverso(v, 100);
		fprintf(Quick, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Quick, ",%d", v[j]);
		}
		fprintf(Quick, ";\n");
		free(v);
	}
	fclose(Quick);
}

void geraHeap() {
	FILE *Heap;

	Heap = fopen("Heap_P.txt", "wt");
	int *v;

	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT;
		}
		fprintf(Heap, "100");
		quick(v, 0, 99);
		for (int j = 0; j < 100; j++) {
			fprintf(Heap, ",%d", v[j]);
		}
		fprintf(Heap, ";\n");
		free(v);
	}
	fclose(Heap);

	Heap = fopen("Heap_M.txt", "wt");
	for (int i = 0; i < 10; i++) {
		v = (int*) malloc(100 * sizeof(int));
		for (int j = 0; j < 100; j++) {
			v[j] = rand() % MAX_INT;
		}
		bubbleInverso(v, 100);
		fprintf(Heap, "100");
		for (int j = 0; j < 100; j++) {
			fprintf(Heap, ",%d", v[j]);
		}
		fprintf(Heap, ";\n");
		free(v);
	}
	fclose(Heap);
}


