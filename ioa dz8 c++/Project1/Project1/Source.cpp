#include<stdio.h>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;
int s[] = { 173669, 275487, 1197613, 1549805, 502334, 217684, 1796841, 274708,
631252, 148665, 150254, 4784408, 344759, 440109, 4198037, 329673, 28602,
144173, 1461469, 187895, 369313, 959307, 1482335, 2772513, 1313997, 254845,
486167, 2667146, 264004, 297223, 94694, 1757457, 576203, 8577828, 498382,
8478177, 123575, 4062389, 3001419, 196884, 617991, 421056, 3017627, 131936,
1152730, 2676649, 656678, 4519834, 201919, 56080, 2142553, 326263, 8172117,
2304253, 4761871, 205387, 6148422, 414559, 2893305, 2158562, 465972, 304078,
1841018, 1915571 };

int opt_fun(int* x) {
	int f1 = pow(2, 25);
	int f2 = pow(2, 25);
	for (int i = 0; i < 64; i++) {
		if (x[i] == 1) {
			f1 -= s[i];
		}
		else {
			if (x[i] == 2) {
				f2 -= s[i];
			}
		}
	}
	if ((f1 >= 0) && (f2 >= 0)) {
		return f1 + f2;
	}
	else {
		return pow(2, 26);
	}
}

void main() {
	int x[64], **generacija, minimum, min_arr[64], ind[20000], pob, parr[64], cnt, **pobednici, glob_minimum, glob_min_arr[64], N=5;
	ofstream fp("file.txt");
	glob_minimum = pow(2, 26) + 1;
	for (int pok = 0; pok < 20; pok++) {
		generacija = new int*[20000];
		for (int j = 0; j < 20000; j++) {
			generacija[j] = new int[64];
			for (int i = 0; i < 64; i++) {
				generacija[j][i] = rand() % 3;
			}
			ind[j] = j;
		}
		minimum = pow(2, 26) + 1;
		for (int t = 0; t < 50; t++) {
			for (int i = 0; i < 20000; i++) {
				int opt = opt_fun(generacija[i]);
				if (opt < minimum) {
					minimum = opt;
					for (int j = 0; j < 64; j++) {
						min_arr[j] = generacija[i][j];
					}
					if (opt < glob_minimum) {
						glob_minimum = opt;
						for (int j = 0; j < 64; j++) {
							glob_min_arr[j] = generacija[i][j];
						}
					}
				}
				if (fp.is_open())
					fp << minimum << " ";
			}
				/*Selekcija:*/
				double e = 20000.0 / N;
				int ekipe = ceil(e);
				pobednici = new int*[ekipe];
				for (int i = 0; i < ekipe; i++) {
					pobednici[i] = new int[64];
				}
				pob = pow(2, 26) + 1;
				random_shuffle(ind, ind + 20000);
				cnt = 0;
				for (int i = 0; i < 20000; i++) {
					int opt = opt_fun(generacija[ind[i]]);
					if (opt < pob) {
						pob = opt;
						for (int j = 0; j < 64; j++) {
							parr[j] = generacija[ind[i]][j];
						}
					}
					if ((i % N == N-1)||(i==19999)) {
						for (int j = 0; j < 64; j++) {
							pobednici[cnt][j] = parr[j];
						}
						cnt++;
						pob = pow(2, 26) + 1;
					}
				}
				
				/*
				int ekipe = 10000;
				pobednici = new int*[10000];
				for (int i = 0; i < 10000; i++) {
					pob = pow(2, 26) + 1;
					int ff;
					pobednici[i] = new int[64];
					for (int j = 0; j < 20000; j++) {
						if ((dali[j] == 1) && (opt_fun(generacija[j])<pob)) {
							pob = opt_fun(generacija[j]);
							ff = j;
						}
					}

					for (int j = 0; j < 64; j++) {
						pobednici[i][j] = generacija[ff][j];
					}
					dali[ff] = 0;
				}
				*/
				/*Ukrstanje:*/
				for (int i = 0; i < 10000; i += 2) {
					double r = 1;
					int uk1;
					int uk2;
					while (r > 0.69) {
						uk1 = rand() % ekipe;
						uk2 = rand() % ekipe;
						while (uk1 == uk2) {
							uk2 = rand() % ekipe;
						}
						r = (double)rand() / RAND_MAX;
					}
					pob = rand() % 64;
					while (pob == 0) {
						pob = rand() % 64;
					}
					for (int j = 0; j < 64; j++) {
						if (j < pob) {
							generacija[i][j] = pobednici[uk1][j];
							generacija[i + 1][j] = pobednici[uk2][j];
						}
						else {
							generacija[i][j] = pobednici[uk2][j];
							generacija[i + 1][j] = pobednici[uk1][j];
						}
					}
				}
 				for (int i = 0; i < ekipe; i++) {
					delete[] pobednici[i];
				}
				delete[] pobednici;
				/*Mutacije:*/
				for (int i = 0; i < 20000; i++) {
					double r = (double)rand() / RAND_MAX;
					if (r < 0.15) {
						int ind = rand() % 64;
						int n = rand() % 3;
						while (n != generacija[i][ind]) {
							n = rand() % 3;
						}
						generacija[i][ind] = n;
					}
				}

		}
		for (int i = 0; i < 20000; i++) {
			delete[] generacija[i];
		}
		delete[] generacija;
		fp << endl;
	}
	fp.close();
	if (glob_minimum < 1500) {
		printf("Globalni minimum je u dozvoljenom opsegu\n");
	}
	else {
		printf("Globalni minimum nije u dozvoljenom opsegu\n");
	}
	printf("Globalni minimum je: %d\n", glob_minimum);
	for (int i = 0; i < 64; i++) {
		printf("%d ", glob_min_arr[i]);
	}

}