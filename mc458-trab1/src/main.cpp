/*
 ============================================================================
 Name        : mc458-trab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <string>
#include <sys/time.h>

using namespace std;

void bubble(int*, int);
void insertion(int*, int);
void merge(int*, int, int);
void quick(int*, int, int);
void heap(int*, int);
void geraBubble();
void geraAleatorios();
void geraInsertion();
void geraMerge();
void geraQuick();
void geraHeap();
vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}
void printV(int* v, int n);

int main(int argc, const char* argv[]) {

	vector<string> temp;
	ifstream infile;
	string line;
	int* v;
	int i = 0;
	timeval start, end;

	int n = 100;

	if (argc <= 2) {
		printf("Erro: Numero de argumentos invalidos!\n");
		return 0;
	}

	for (int z = 0; z < 100; z++) {

		if (!strcmp(argv[2], "-bm")) {
			infile.open("Bubble_M.txt");
		} else if (!strcmp(argv[2], "-bp")) {
			infile.open("Bubble_P.txt");
		} else if (!strcmp(argv[2], "-im")) {
			infile.open("Insertion_M.txt");
		} else if (!strcmp(argv[2], "-ip")) {
			infile.open("Insertion_P.txt");
		} else if (!strcmp(argv[2], "-mm")) {
			infile.open("Merge_M.txt");
		} else if (!strcmp(argv[2], "-mp")) {
			infile.open("Merge_P.txt");
		} else if (!strcmp(argv[2], "-qm")) {
			infile.open("Quick_M.txt");
		} else if (!strcmp(argv[2], "-qp")) {
			infile.open("Quick_P.txt");
		} else if (!strcmp(argv[2], "-hm")) {
			infile.open("Heap_M.txt");
		} else if (!strcmp(argv[2], "-hp")) {
			infile.open("Heap_P.txt");
		} else {
			infile.open("Aleatorios.txt");
		}

		while (getline(infile, line)) {

			if (!strcmp(argv[2], "-a")) {
				n = 20 * (i + 1);
			}
			v = (int*) malloc(n * sizeof(int));
			temp = split(line, ',');

			for (int j = 1; j < n; j++) {
				v[j - 1] = atoi(temp.at(j).c_str());
			}

			gettimeofday(&start, NULL);
			if (!strcmp(argv[1], "-b")) {
				bubble(v, n);
			}
			if (!strcmp(argv[1], "-i")) {
				insertion(v, n);
			}
			if (!strcmp(argv[1], "-m")) {
				merge(v, 0, n - 1);
			}
			if (!strcmp(argv[1], "-q")) {
				quick(v, 0, n - 1);
			}
			if (!strcmp(argv[1], "-h")) {
				heap(v, n);
			}
			if (!strcmp(argv[1], "-g")) {
				geraBubble();
				geraAleatorios();
				geraInsertion();
				geraMerge();
				geraQuick();
				geraHeap();
				break;
			}

			free(v);
			i++;
			if (!strcmp(argv[2], "-a")) {
				gettimeofday(&end, NULL);
				printf("Tempo %d: %ld us\n", n, end.tv_usec - start.tv_usec);
				gettimeofday(&start, NULL);
			}

		}
		gettimeofday(&end, NULL);

		suseconds_t time = end.tv_usec - start.tv_usec;

		infile.close();

		printf("Tempo: %ld us\n", time);

	}

	return EXIT_SUCCESS;
}

void printV(int* v, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

