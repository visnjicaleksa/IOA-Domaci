#include<stdio.h>
#include<time.h>

bool prviZadatak(int c1, int c2, int c3, int c4) {
	return ((c1 + c2 + c3 + c4 == 777) && (c1*c2*c3*c4 == 777000000));
}

bool drugiZadatak(int c1, int c2, int c3, int c4) {
	return c1*c2*c3*c4 == 777000000;
}

void main() {
	int cena1, cena2, cena3, cena4;
	bool dali = false;
	time_t t1, t2, t3, t4;
	time(&t1);
	for (int i1 = 1; i1 <= 774; i1++) {
		for (int i2 = 1; i2 <= 774; i2++) {
			for (int i3 = 1; i3 <= 774; i3++) {
				for (int i4 = 1; i4 <= 774; i4++) {
					if (prviZadatak(i1, i2, i3, i4)) {
						dali = true;
						cena1 = i1;
						cena2 = i2;
						cena3 = i3;
						cena4 = i4;
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
		if (dali) {
			break;
		}
	}
	time(&t2);
	printf("cena 1 je %d centi\ncena 2 je %d centi\ncena 3 je %d centi\ncena 4 je %d centi\n", cena1, cena2, cena3, cena4);
	printf("Maksimalan broj poziva optimizacione funkcije je 774 * 774 * 774 * 774\n");

	int cena1_2, cena2_2, cena3_2, cena4_2;
	dali = false;
	time(&t3);
	for (int i1 = 1; i1 <= 774; i1++) {
		for (int i2 = 1; i2 <= 774; i2++) {
			for (int i3 = 1; i3 <= 774; i3++) {
				int i4 = 777 - (i1 + i2 + i3);
				if (drugiZadatak(i1, i2, i3, i4)) {
					dali = true;
					cena1_2 = i1;
					cena2_2 = i2;
					cena3_2 = i3;
					cena4_2 = i4;
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
	time(&t4);
	printf("cena 1 je %d centi\ncena 2 je %d centi\ncena 3 je %d centi\ncena 4 je %d centi\n", cena1_2, cena2_2, cena3_2, cena4_2);
	printf("Maksimalan broj poziva optimizacione funkcije je 774 * 774 * 774\n");
	if ((t4 - t3) < (t2 - t1)) {
		printf("Program b je brzi od programa a\n");
	}
	else {
		if ((t4 - t3) > (t2 - t1)) {
			printf("Program a je brzi od programa b\n");
		}
		else {
			printf("Podjednako su brzi\n");
		}
	}
}