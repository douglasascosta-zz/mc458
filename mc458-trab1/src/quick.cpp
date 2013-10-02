#include <stdio.h>

int particiona(int*, int, int);

void quick(int* a, int l, int r) {
	int j;

	if (l < r) {
		// divide and conquer
		j = particiona(a, l, r);
		quick(a, l, j - 1);
		quick(a, j + 1, r);
	}

}

int particiona(int* a, int l, int r) {
	int pivot, i, j, t;
	pivot = a[l];
	i = l;
	j = r + 1;

	while (1) {
		do
			++i;
		while (a[i] <= pivot && i <= r);
		do
			--j;
		while (a[j] > pivot);
		if (i >= j)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[l];
	a[l] = a[j];
	a[j] = t;
	return j;
}

// escolhe-se um pivô e ordena a lista para que todos sejam menores a esquerda e maiores a direita
// aplica-se recursivamente o metodo a lista da esquerda e da direita
// pior caso O(n²)
// melhor caso O(n logn)
