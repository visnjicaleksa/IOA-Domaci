#include<stdio.h>
#include<vector>


using namespace std;
 bool opt_fun(int c1, int c2, int c3, int c4, int val) {
	return c1*c2*c3*c4 == (val*1000000);
}

void main() {
	vector<int> v;
	bool dali = false;
	printf("Cene su izracene u centima:\n");
	for (int c = 4; c < 1000; c++) {
		dali = false;
		for (int i1 = 1; i1 <= (c-3); i1++) {
			for (int i2 = 1; i2 <= (c-3); i2++) {
				for (int i3 = 1; i3 <= (c-3); i3++) {
					int i4 = c - (i1 + i2 + i3);
					if (i4 <= 0) {
						break;
					}
					if (opt_fun(i1, i2, i3, i4, c)) {
						dali = true;
						//printf("%d ", c);
						printf("Ukupna cena je: %d Prva cena je: %d Druga cena je: %d Treca cena je: %d Cetvrta cena je: %d\n", c, i1, i2, i3, i4);

						break;
					}
				}
				if (dali) {
					break;
				}

			}
			if (dali) {
				break;
			}
		}
	}
}