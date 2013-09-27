void bubble(int *v, int n) {
	int i;
	int j;
	int aux;
	int k = n - 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			if (v[j] > v[j + 1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
		k--;
	}
}

// vai ordenando os elementos de dois em dois, trocando-os se o da esquerda foi maior que o da direita
// pior caso O(n²)
// melhor caso O(n)

