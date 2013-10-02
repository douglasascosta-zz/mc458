#include <stdio.h>

int particiona(int*, int, int);

void quick(int* v, int l, int r) {
	int j;

	if (l < r) {
		// divide and conquer
		j = particiona(v, l, r);
		quick(v, l, j - 1);
		quick(v, j + 1, r);
	}

}

int particiona(int* v, int l, int r) {
	int pivot, i, j, t;
	pivot = v[l];
	i = l;
	j = r + 1;

	while (true) {
		do
			++i;
		while (v[i] <= pivot && i <= r);
		do
			--j;
		while (v[j] > pivot);
		if (i >= j)
			break;
		t = v[i];
		v[i] = v[j];
		v[j] = t;
	}
	t = v[l];
	v[l] = v[j];
	v[j] = t;
	return j;
}

// escolhe-se um pivô e ordena a lista para que todos sejam menores a esquerda e maiores a direita
// aplica-se recursivamente o metodo a lista da esquerda e da direita
// pior caso O(n²)
// melhor caso O(n logn)
