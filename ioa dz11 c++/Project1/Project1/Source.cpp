#define _USE_MATH_DEFINES
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<fstream>

using namespace std;


double opt_fun1(double a, double b, double s) {
	double z0 = b / 2 + 0.01;
	double I = 1;
	double temp = ((z0 + b / 2) / (sqrt(pow(a, 2) + pow((z0 + b / 2), 2)))) - 
		((z0 - b / 2) / (sqrt(pow(a, 2) + pow((z0 - b / 2), 2))));
	double H = (I / 2) * sqrt(M_PI / (4 * s))*temp;
	return H;
	
}


double opt_fun2(double a, double b, double s) {
	double omega = 58000000;
	return (2 * M_PI*a*b) / (omega*s)*sqrt(M_PI / (4 * s));
	
}


void main() {
	bool dali;
	double a, b, s, *H, *r;
	vector<int> pf;
	ofstream fp("file.txt");
	H = new double[1000000];
	r = new double[1000000];
	for (int i = 0; i < 1000000; i++) {
		a=pow(10,-2) + (4*pow(10,-2))*((double)rand() / RAND_MAX);
		b = 0.1 + 0.3*((double)rand() / RAND_MAX);
		s = 1/2*pow(10, -6) + (3 * pow(10, -6)-(1/2)*pow(10,-6))*((double)rand() / RAND_MAX);
		H[i] = opt_fun1(a, b, s);
		r[i] = opt_fun2(a, b, s);
	}
	for (int i = 0; i < 1000000; i++) {
		dali = true;
		for (int j = 0; j < 1000000; j++) {
			if ((H[i] < H[j]) && (r[i] > r[j])) {
				dali = false;
				break;
			}
		}
		if (dali) {
			pf.push_back(i);
		}
	}
	if (fp.is_open()) {
		for (int i = 0; i < 1000000; i++) {
			fp << H[i]<<" ";
		}
		fp << "\n";
		for (int i = 0; i < 1000000; i++) {
			fp << r[i] << " ";
		}
		fp << "\n";
		for(int f:pf) {
			fp << f << " ";
		}
	}
	else {
		cout << "Greska!"<< endl;
	}
	fp.close();
	pf.clear();
	delete[] H;
	delete[] r;

}