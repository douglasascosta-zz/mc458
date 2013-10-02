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

void bubble(int*, int);
void insertion(int*, int);
void merge(int*, int, int);
void quick(int*, int, int);
void heap(int*, int);
void geraBubble();
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string, char);
void printV(int* v, int n);

int main(int argc, const char* argv[]) {

	if (argc > 2){
		for (int i = 2; i < argc; i++){
			printf("%s ",argv[i]);
		}
	}

	using namespace std;
	const string str;
	vector<string> temp;
	FILE *f;
	clock_t start;
	double duration;

	start = std::clock();
	int n = 100;
	int* v = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < 10; i++) {
		printf("Antes:\n");

		if (strcmp(argv[1], "-b") == 0) {
			f = fopen("Bubble_M.txt", "rd");

			for (int j = 0; j < n; j++) {
				temp = split(str, ",");
			}

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
		if (strcmp(argv[1], "-g") == 0) {
			printf("\nGera Vetores:\n");
			geraBubble();
		}

		printf("Depois:\n");
		printV(v, n);

	}

	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "printf: " << duration << '\n';

	return EXIT_SUCCESS;
}

void printV(int* v, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
