#include<stdio.h>
#include<iostream>
#include<math.h>
#include<float.h>

using namespace std;
struct Rupa
{
	double x;
	double y;
};


int next_permutation(const int n, int *p) {
	int s;
	int* first = &p[0];
	int* last = &p[n - 1];
	int* k = last - 1;
	int* l = last;
	while (k > first) {
		if (*k < *(k + 1)) {
			break;
		}
		k--;
	}
	if (*k > *(k + 1)) {
		return 0;
	}
	while (l > k) {
		if (*l > *k) {
			break;
		}
		l--;
	}
	s = *k;
	*k = *l;
	*l = s;
	first = k + 1;
	while (first < last) {
		s = *first;
		*first = *last;
		*last = s;
		first++;
		last--;
	}
	return 1;

}
double razdaljina(Rupa r1, Rupa r2) {
	double razd= sqrt(pow(r1.x - r2.x, 2) + pow(r1.y - r2.y, 2));
	return razd;
}
double putanja(int n, int *p, Rupa *rupa) {
	double dist = 0;
	for (int i = 0; i < n - 1; i++) {
		dist += razdaljina(rupa[p[i] - 1], rupa[p[i + 1] - 1]);
	}
	return dist;
}
void main() {
	double najmanja = DBL_MAX;
	Rupa rupe1[8] = {
		{ 62.0, 58.4 },
		{ 57.5, 56.0 },
		{ 51.7, 56.0 },
		{ 67.9, 19.6 },
		{ 57.7, 42.1 },
		{ 54.2, 29.1 },
		{ 46.0, 45.1 },
		{ 34.7, 45.1 }
	};

	int redosled[8] = { 0,0,0,0,0,0,0,0 };
	int *n = new int[8];
	for (int i = 0; i < 8; i++) {
		n[i] = i + 1;
	}
	do {
		double put = putanja(8, n, rupe1);
		if (put < najmanja) {
			najmanja = put;
			for (int i = 0; i < 8; i++) {
				redosled[i] = n[i];
			}
		}

	} while (next_permutation(8, n));
	cout << "Za 8 rupa" << endl;
	cout << "Najmanja distanca je: "<<najmanja << endl;
	cout << "Redosled obilaska je: " << endl;
	for (int i = 0; i < 8; i++) {
		cout << redosled[i]<<" ";
	}
	cout << endl;
	delete[] n;

	najmanja = DBL_MAX;
	Rupa rupe2[12] = {
		{ 62.0, 58.4 },
		{ 57.5, 56.0 },
		{ 51.7, 56.0 },
		{ 67.9, 19.6 },
		{ 57.7, 42.1 },
		{ 54.2, 29.1 },
		{ 46.0, 45.1 },
		{ 34.7, 45.1 },
		{ 45.7, 25.1 },
		{ 34.7, 26.4 },
		{ 28.4, 31.7 },
		{ 33.4, 60.5 }
	};
	int redosled2[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	n = new int[12];
	for (int i = 0; i < 12; i++) {
		n[i] = i + 1;
	}
	do {
		double put = putanja(12, n, rupe2);
		if (put < najmanja) {
			najmanja = put;
			for (int i = 0; i < 12; i++) {
				redosled2[i] = n[i];
			}
		}

	} while (next_permutation(12, n));
	cout << "Za 12 rupa" << endl;
	cout << "Najmanja distanca je: " << najmanja << endl;
	cout << "Redosled obilaska je: " << endl;
	for (int i = 0; i < 12; i++) {
		cout << redosled2[i] << " ";
	}
	cout << endl;
	delete[] n;
}