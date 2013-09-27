#include <stdlib.h>

void merge2(int *v, int inicio, int meio, int fim);

void merge(int *v, int inicio, int fim) {
	int meio;

	if (inicio == fim) {
		return;
	}

	meio = (inicio + fim) / 2;
	merge(v, inicio, meio);
	merge(v, meio + 1, fim);

	merge2(v, inicio, meio, fim);
}

void merge2(int *v, int inicio, int meio, int fim) {
	int *vetorTemp;

	int i = inicio;
	int j = meio + 1;
	int k = 0;
	vetorTemp = (int *) malloc(sizeof(int) * (fim - inicio + 1));

	while (i < meio + 1 || j < fim + 1) {
		if (i == meio + 1) { // i passou do final da primeira metade, pegar v[j]
			vetorTemp[k] = v[j];
			j++;
			k++;
		} else {
			if (j == fim + 1) {
				// j passou do final da segunda metade, pegar v[i]
				vetorTemp[k] = v[i];
				i++;
				k++;
			} else {
				if (v[i] < v[j]) {
					vetorTemp[k] = v[i];
					i++;
					k++;
				} else {
					vetorTemp[k] = v[j];
					j++;
					k++;
				}
			}
		}

	}
	// copia vetor intercalado para o vetor original
	for (i = inicio; i <= fim; i++) {
		v[i] = vetorTemp[i - inicio];
	}
	free(vetorTemp);
}

// dividindo o vetor e unindo-os e ordenando recursivamente
// pior caso TETA(n logn)
// melhor caso TETA(
