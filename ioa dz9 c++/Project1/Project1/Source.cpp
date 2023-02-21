#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;
double S[20] = { 2.424595205726587e-01, 1.737226395065819e-01, 1.315612759386036e-01,
1.022985539042393e-01, 7.905975891960761e-02, 5.717509542148174e-02,
3.155886625106896e-02, -6.242228581847679e-03, -6.565183775481365e-02,
-8.482380513926287e-02, -1.828677714588237e-02, 3.632382803076845e-02,
7.654845872485493e-02, 1.152250132891757e-01, 1.631742367154961e-01,
2.358469152696193e-01, 3.650430801728451e-01, 5.816044173713664e-01,
5.827732223753571e-01, 3.686942505423780e-01 };

double opt_fun(double xp1, double yp1, double xp2, double yp2, double a1, double a2) {
	double c1 = sqrt(pow(xp1, 2) + pow(xp2, 2));
	double c2 = sqrt(pow(yp1, 2) + pow(yp2, 2));
	if ((c1 >= 15) || (c2 >= 15)) {
		return 100;
	}
	else {
		double sum = 0;
		for (int i = 0; i < 20; i++) {
			double xi = 15 * cos(2 * M_PI *i / 20);
			double yi = 15 * sin(2 * M_PI * i / 20);
			double deo1 = a1 / (sqrt(pow((xi - xp1), 2) + pow((yi - yp1), 2)));
			double deo2 = a2 / (sqrt(pow((xi - xp2), 2) + pow((yi - yp2), 2)));
			sum += pow((deo1 + deo2 - S[i]),2);
		}
		return sum;
	}
}

void main() {
	double **generacija, **pobednici, glob_minimum, minimum, min_arr[6], glob_min_arr[6], izgenerisan[6], izgenerisan2[6], F=0.8, cr=0.9;
	int x[64], ind[3], pob, parr[64], cnt, N = 5;
	bool nije, dali;
	glob_minimum = 101;
		generacija = new double*[60];
		for (int j = 0; j < 60; j++) {
			generacija[j] = new double[6];
			for (int i = 0; i < 6; i++) {
				double f = (double)rand() / RAND_MAX;
				generacija[j][i] = -15 + f * 30;
			}
			
		}
		dali = false;
		minimum = 101;
		while(1) {
			for (int i = 0; i < 60; i++) {
				double opt = opt_fun(generacija[i][0], generacija[i][1], generacija[i][2], generacija[i][3], generacija[i][4], generacija[i][5]);
				if (opt < minimum) {
					minimum = opt;
					for (int j = 0; j < 6; j++) {
						min_arr[j] = generacija[i][j];
					}
					if (opt < glob_minimum) {
						glob_minimum = opt;
						for (int j = 0; j < 6; j++) {
							glob_min_arr[j] = generacija[i][j];
						}
						if (glob_minimum < 1e-14) {
							dali = true;
							break;
						}
					}
				}
				
			}
			if (dali) {
				break;
			}
			else {
				/*Selekcija:*/
				pobednici = new double*[60];
				for (int j = 0; j < 60; j++) {
					pobednici[j] = new double[6];
				}
				for (int i = 0; i < 60; i++) {
					for (int j = 0; j < 3; j++) {
						nije = false;
						while (!nije) {
							nije = true;
							int r = rand() % 60;
							while (r == i) {
								r = rand() % 60;
							}
							for (int k = 0; k < sizeof(ind) / sizeof(double); k++) {
								if (ind[k] == r) {
									nije = false;
								}
							}
							if (nije) {
								ind[j] = r;
							}
						}
					}
					for (int j = 0; j < 6; j++) {
						izgenerisan[j] = generacija[ind[0]][j] + F*(generacija[ind[1]][j] - generacija[ind[2]][j]);
					}
					int R = rand() % 6;
					for (int j = 0; j < 6; j++) {
						double r = (double)rand() / RAND_MAX;
						if ((R == j) || (r < cr)) {
							izgenerisan2[j] = izgenerisan[j];
						}
						else {
							izgenerisan2[j] = generacija[i][j];
						}
					}
					double o1 = opt_fun(generacija[i][0], generacija[i][1], generacija[i][2], generacija[i][3], generacija[i][4], generacija[i][5]);
					double o2 = opt_fun(izgenerisan2[0], izgenerisan2[1], izgenerisan2[2], izgenerisan2[3], izgenerisan2[4], izgenerisan2[5]);
					if (o2 < o1) {
						for (int j = 0; j < 6; j++) {
							pobednici[i][j] = izgenerisan2[j];
						}
					}
					else {
						for (int j = 0; j < 6; j++) {
							pobednici[i][j] = generacija[i][j];
						}
					}
				}
				for (int i = 0; i < 60; i++) {
					for (int j = 0; j < 6; j++) {
						generacija[i][j] = pobednici[i][j];
					}
				}

				for (int i = 0; i < 6; i++) {
					delete[] pobednici[i];
				}
				delete[] pobednici;

			}
		}
		for (int i = 0; i < 6; i++) {
			delete[] generacija[i];
		}
		delete[] generacija;
	if (glob_minimum < 1e-14) {
		cout << "Optimizaciona funkcija je u dozvoljenom opsegu." << endl;
	}
	else {
		cout << "Optimizaciona funkcija nije u dozvoljenom opsegu." << endl;
	}
	printf("Optimizaciona funkcija je: %.20f\n", glob_minimum);
	//cout << "Optimizaciona funkcija je: " << glob_minimum << endl;
	for (int i = 0; i < 6; i++) {
		printf("%.20f ", glob_min_arr[i]);
		//cout << glob_min_arr[i] << " ";
	}

}