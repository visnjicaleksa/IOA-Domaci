#include<stdio.h>
#include<cmath>
#include<float.h>
double opt_fun(double x1, double y1, double z1, double x2, double y2, double z2) {
	double dist = 0;
	dist += sqrt(pow((x1 - 1), 2) + pow((y1 - 4), 2) + pow((z1 - 0), 2)) +
		sqrt(pow((x1 - 3), 2) + pow((y1 - 2), 2) + pow((z1 - 0), 2)) +
		sqrt(pow((x1 - 2), 2) + pow((y1 - 7), 2) + pow((z1 - 1), 2)) +
		sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2)) +
		sqrt(pow((x2 - 6), 2) + pow((y2 - 3), 2) + pow((z2 - 3), 2)) +
		sqrt(pow((x2 - 7), 2) + pow((y2 - 6), 2) + pow((z2 - 5), 2)) +
		sqrt(pow((x2 - 5), 2) + pow((y2 - 7), 2) + pow((z2 - 4), 2));
	return dist;

}

void main() {
	double **agent, **pbest, *gbest, w = 0.729, c1 = 1.494, c2 = 1.494, v[6], **vp, opt_glob=DBL_MAX, agent_pr[6], gbest_p[6];
	bool dali=false;
	agent = new double*[60];
	pbest = new double*[60];
	vp = new double*[60];
	gbest = new double[6];
	for (int i = 0; i < 60; i++) {
		vp[i]= new double[6];
		pbest[i]= new double[6];
		agent[i] = new double[6];
		for (int j = 0; j < 6; j++) {
			agent[i][j] = (double)rand() / RAND_MAX;
			agent[i][j] *= 10;
			pbest[i][j] = agent[i][j];
			vp[i][j] = 0;
		}
		if ((i == 0) || (opt_fun(agent[i][0], agent[i][1], agent[i][2], agent[i][3], agent[i][4], agent[i][5])<opt_glob)) {
			for (int j = 0; j < 6; j++) {
				gbest[j] = agent[i][j];
			}
			opt_glob = opt_fun(agent[i][0], agent[i][1], agent[i][2], agent[i][3], agent[i][4], agent[i][5]);
		}
	}

	for (int t = 0; t < 100; t++) {
		if (dali) {
			break;
		}
		for (int j = 0; j < 6; j++) {
			gbest_p[j] = gbest[j];
		}
		for (int i = 0; i < 60; i++) {
			for (int j = 0; j < 6; j++) {
				v[j] = vp[i][j] * w + c1*((double)rand() / RAND_MAX)*(pbest[i][j] - agent[i][j]) + c2*((double)rand() / RAND_MAX)*(gbest[j] - agent[i][j]);
				if (v[j] > 2) {
					v[j] = 2;
				}
				else {
					if (v[j] < -2) {
						v[j] = -2;
					}
				}
				agent[i][j] += v[j];
				vp[i][j] = v[j];
			}
			if (opt_fun(agent[i][0], agent[i][1], agent[i][2], agent[i][3], agent[i][4], agent[i][5]) < opt_fun(pbest[i][0], pbest[i][1], pbest[i][2], pbest[i][3], pbest[i][4], pbest[i][5])) {
				for (int j = 0; j < 6; j++) {
					pbest[i][j] = agent[i][j];
				}
			}
			if (opt_fun(agent[i][0], agent[i][1], agent[i][2], agent[i][3], agent[i][4], agent[i][5]) < opt_glob) {
				for (int j = 0; j < 6; j++) {
					gbest[j] = agent[i][j];
				}
				opt_glob = opt_fun(agent[i][0], agent[i][1], agent[i][2], agent[i][3], agent[i][4], agent[i][5]);
			}
		}
		printf("%.15f\n", opt_glob);
		dali = true;
		for (int i = 0; i < 6; i++) {
			if (abs(gbest_p[i] - gbest[i]) >= 1e-3) {
				dali = false;
			}
		}
	}
	if (!dali) {
		printf("Zavrsila se poslednja iteracija");
	}
	printf("%.15f\n", opt_fun(gbest[0], gbest[1], gbest[2], gbest[3], gbest[4], gbest[5]));
	for (int i = 0; i < 6; i++) {
		printf("%.15f ", gbest[i]);
	}
	printf("\n");
	/*for (int i = 0; i < 6; i++) {
		printf("%.15f ", gbest_p[i]);
	}*/
	for (int i = 0; i < 60; i++) {
		delete[] agent[i];
		delete[] pbest[i];
		delete[] vp[i];
	}
	delete[] agent;
	delete[] pbest;
	delete[] vp;
	delete[] gbest;
}