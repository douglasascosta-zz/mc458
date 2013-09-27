void insertion(int *v, int n) {
	int i, aux;

	for (i = 1; i < n; i++) {
		while ((i != 0) && (v[i - 1] > v[i])) {

			aux = v[i];
			v[i] = v[i - 1];
			v[i - 1] = aux;
			i--;
		}
	}
}

// vai ordenando os elementos a esquerda a medida que avança no vetor para a direita
// pior caso O(n²)
// melhro caso O(n)
