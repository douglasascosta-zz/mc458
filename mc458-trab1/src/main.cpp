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

using namespace std;

void bubble(int*, int);
void insertion(int*, int);
void merge(int*, int, int);
void quick(int*, int, int);
void heap(int*, int);
void geraBubble();
void geraAleatorios();
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
	clock_t start;
	double duration;
	ifstream infile;
	string line;
	int* v;
	int i = 0;

	start = clock();
	int n = 100;

	if (argc <= 2) {
		printf("Erro: Numero de argumentos invalidos!\n");
		return 0;
	}

	if (strcmp(argv[2], "-bm")) {
		infile.open("Bubble_M.txt");
	} else if (strcmp(argv[2], "-bp")) {
		infile.open("Bubble_P.txt");
	} else if (strcmp(argv[2], "-im")) {
		infile.open("Insertion_M.txt");
	} else if (strcmp(argv[2], "-ip")) {
		infile.open("Insertion_P.txt");
	} else if (strcmp(argv[2], "-mm")) {
		infile.open("Merge_M.txt");
	} else if (strcmp(argv[2], "-mp")) {
		infile.open("Merge_P.txt");
	} else if (strcmp(argv[2], "-qm")) {
		infile.open("Quick_M.txt");
	} else if (strcmp(argv[2], "-qp")) {
		infile.open("Quick_P.txt");
	} else if (strcmp(argv[2], "-hm")) {
		infile.open("Heap_M.txt");
	} else if (strcmp(argv[2], "-hp")) {
		infile.open("Heap_P.txt");
	} else {
		infile.open("Aleatorios.txt");
	}

	while (getline(infile, line)) {
		printf("Antes %d:\n", i + 1);

		//Bubble sort
		if (strcmp(argv[1], "-b") == 0) {
			if (strcmp(argv[2], "-a")) {
				n = 20 * (i + 1);
			}
			v = (int*) malloc(n * sizeof(int));

			temp = split(line, ',');

			temp.at(temp.size() - 1) = temp.at(temp.size() - 1).substr(0,
					temp.at(temp.size() - 1).size() - 2);

			for (int j = 1; j <= n; j++) {
				v[j] = atoi(temp.at(j+1).c_str());
			}
			printV(v, n);
			bubble(v, n);
		} //Fim do bloco do Bubble

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
		if (strcmp(argv[1], "-g") == 0) {
			printf("\nGera Vetores:\n");
			geraBubble();
			geraAleatorios();
			break;
		}

		printf("Depois %d:\n", i + 1);
		printV(v, n);
		free(v);
		i++;

	}

	infile.close();

	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "printf: " << duration << '\n';

	return EXIT_SUCCESS;
}

void printV(int* v, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

