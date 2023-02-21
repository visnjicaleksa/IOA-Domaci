#include<stdio.h>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<fstream>

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
	int hmin = 1, hmax = 7, x[64], arr[64], opt_f, minimum, minarr[64], lok_min;
	double a = 0.95;
	ofstream fp("file.txt");
	for (int m = 0; m < 20; m++) {
		for (int i = 0; i < 64; i++) {
			x[i] = rand() % 3;
		}
		opt_f = opt_fun(x);
		if (m == 0) {
			minimum = opt_f;
		}
		lok_min = opt_f;
		for (int j = 0; j < 10; j++) {
			double t = 64 * 1024 * 1024;
			for (int k = 0; k < 100000; k++) {
				for (int i = 0; i < 64; i++) {
					arr[i] = x[i];
				}
				vector<int> arrch;
				double hii = ((hmin - hmax) / (100000 - 1))*(k - 1) + hmax;
				int hi = round(hii);
				for (int i = 0; i < hi; i++) {
					arrch.push_back(rand() % 64);
				}
				for (int l : arrch) {
					arr[l] = rand() % 3;
				}
				int deltae = opt_fun(arr) - opt_f;
				if (deltae < 0) {
					for (int i = 0; i < 64; i++) {
						x[i] = arr[i];
					}
				}
				else {
					double p;
					if (deltae == 0) {
						p = 0.5;
					}
					else {
						p = exp(-deltae / t);
					}
					double r = (double)rand() / RAND_MAX;
					//printf("%f", r);
					if ((p - r) < 0) {
						for (int i = 0; i < 64; i++) {
							x[i] = arr[i];
						}
					}
				}
				t *= a;
				opt_f = opt_fun(x);
				if (opt_f < lok_min) {
					lok_min = opt_f;
				}
				if (fp.is_open())
					fp << lok_min << " ";
				else {
					printf("Greska!");
				}
				if (opt_f < minimum) {
					minimum = opt_f;
					for (int i = 0; i < 64; i++) {
						minarr[i] = x[i];
					}
				}
			}
		}
		fp << endl;

	}
	if (minimum < 1500) {
		printf("Vrednost je u dozvoljenom opsegu.\n");
	}
	else {
		printf("Vrednost nije u dozvoljenom opsegu.\n");
	}
	printf("Minimalna vrednost optimizacione funlcije je: %d\n", minimum);
	printf("Parametri x su: \n");
	for (int i : minarr)
		printf("%d ", i);
	fp.close();
}