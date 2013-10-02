void heap(int* v, int n) {
	int i = n / 2, pai, filho, t;

	for (;;) {
		if (i > 0) {
			i--;
			t = v[i];
		} else {
			n--;
			if (n == 0)
				return;
			t = v[n];
			v[n] = v[0];
		}

		pai = i;

		/*
		 Primeiro será feita a comparação com o filho da esquerda.
		 */
		filho = i * 2;

		while (filho < n) {
			/*
			 Se o filho da esquerda for menor do que o filho da direita,
			 então será feita a troca do filho que será comparado.
			 */
			if ((filho + 1 < n) && (v[filho + 1] > v[filho]))
				filho++;
			if (v[filho] > t) {
				v[pai] = v[filho];
				pai = filho;
				filho = pai * 2 + 1;
			} else
				break;
		}
		v[pai] = t;
	}
}
