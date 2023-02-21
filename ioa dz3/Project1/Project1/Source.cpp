#include<stdio.h>
#include<limits.h>

int cena[10][10] = { { 0,374,350,223,108,178,252,285,240,356 },
{ 374,0,27,166,433,199,135,95,136,17 },
{ 350,27,0,41,52,821,180,201,131,247 },
{ 223,166,41,0,430,47,52,84,40,155 },
{ 108,433,52,430,0,453,478,344,389,423 },
{ 178,199,821,47,453,0,91,37,64,181 },
{ 252,135,180,52,478,91,0,25,83,117 },
{ 285,95,201,84,344,37,25,0,51,42 },
{ 240,136,131,40,389,64,83,51,0,118 },
{ 356,17,247,155,423,181,117,42,118,0 } };

int* min_cena_stablo;
int min_cena;

void SequenceToSpanningTree(int *P, int len, int *T) {

	int i, j, q = 0;
	int n = len + 2;
	int *V = new int[n];
	for (i = 0; i < n; i++) {
		V[i] = 0;
	}
	for (i = 0; i < len; i++) {
		V[P[i] - 1] += 1;
	}
	for (i = 0; i < len; i++) {
		for (j = 0; j < n; j++) {
			if (V[j] == 0) {
				V[j] = -1;
				T[q++] = j + 1;
				T[q++] = P[i];
				V[P[i] - 1]--;
				break;
			}
		}
	}
	j = 0;
	for (i = 0; i < n; i++) {
		if (V[i] == 0 && j == 0) {
			T[q++] = i + 1;
			j++;
		}
		else
			if (V[i] == 0 && j == 1) {
				T[q++] = i + 1;
				break;
			}
	}
	delete[] V;
}

void racunaj_cenu(int *T, int l) {
	int c = 0;
	int pon[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < l; i += 2) {
		c += cena[T[i] - 1][T[i + 1] - 1];
		pon[T[i] - 1]++;
		pon[T[i + 1] - 1]++;
	}
	for (int i = 0; i < 10; i++) {
		if (pon[i] >= 4) {
			c += 250;
		}
	}
	if (c < min_cena) {
		min_cena = c;
		for (int i = 0; i < l; i++) {
			min_cena_stablo[i] = T[i];
		}
	}
}

void variations_with_repetitions(int n, int k) {
	int q;
	int *P = new int[k];
	for (int i = 0; i < k; i++) {
		P[i] = 1;
	}
	do {
		/*	for (int i = 0; i < k; i++) {
		printf("%5d ", P[i]);
		}*/
		int* T = new int[2 * (k + 1)];
		SequenceToSpanningTree(P, k, T);
		racunaj_cenu(T, 2 * (k + 1));
		delete[] T;
		//printf("\n");
		q = k - 1;
		while (q >= 0) {
			P[q]++;
			if (P[q] == n + 1) {
				P[q] = 1;
				q--;
			}
			else
				break;
		}
	} while (q >= 0);

	delete[] P;
}

void main() {
	min_cena_stablo = new int[18];
	for (int i = 0; i < 18; i++) {
		min_cena_stablo[i] = 0;
	}
	min_cena = INT_MAX;
	variations_with_repetitions(10, 8);
	printf("Najmanja cena povezivanja je: %d\n", min_cena);
	for (int i = 0; i < 18; i += 2) {
		printf("%c ", 64 + min_cena_stablo[i]);
		printf("%c ", 64 + min_cena_stablo[i + 1]);
		if (i < 16) {
			printf("- ");
		}
	}
	printf("\n");
	/*int P[] = { 1,1,1 };
	int len = sizeof(P) / sizeof(P[0]);
	int* T = new int[2 * (len + 1)];
	SequenceToSpanningTree(P, len, T);
	for (int i = 0; i < 2 * (len + 1); i++) {
	printf(" %d", T[i]);
	if ((i + 1) % 2 == 0 && i < 2 * len)
	printf(" - ");
	}
	printf("\n");
	delete[] T;*/
}