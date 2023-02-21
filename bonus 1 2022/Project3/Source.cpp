#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<string>

using namespace std;

void main() {

	unsigned long long int k = 18446744073709551615;
	long long int num = 1;
	int s = 1;
	for (long long int i = 1; i < k; i++) {
		long long int p = num*i;
		if (num > p) {
			s = i;
			break;
		}
		num = num*i;
	}
	num = 2*1;
	int breakcnt = 0;
	long long int num2;
	bool dali=false;
	for (int i = 3; i < s; i++) {
		num *= i;
		for (long long int j = 1; j < num-1; j++) {
			for (long long int m = 1; m < num-1; m++) {
				for (long long int n = 1; n < num - 1; n++) {
					long long int s1 = pow(j, i - 1);
					long long int s2 = pow(m, i - 1);
					long long int s3 = pow(n, i - 1);
					num2 = s1 + s2 + s3;
					if (num2<0) {
						dali = true;
					}
					
					if (num == num2) {
						printf("(%lld, %lld, %lld, %d)\n", j, m, n, i);
						dali = false;
						breakcnt = 0;
					}
					else {
						if (num2 > num) {
							breakcnt++;
							break;
						}
						else {
							if (dali) {
								breakcnt++;
								break;
							}
						}
						breakcnt = 0;
						dali = 0;
					}
				}
				if (((num2 > num)&&(breakcnt>=2))||(dali&&(breakcnt>=2))) {
					breakcnt++;
					break;
				}
			}
			if (((num2 > num) && (breakcnt >= 5)) || (dali && (breakcnt >= 5))) {
				breakcnt++;
				break;
			}
		}
	}
}