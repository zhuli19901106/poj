#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const double pi = 3.1415926535;
double s;
double r, r2, h, h2;
double v;

int main()
{
	while(scanf("%lf", &s) == 1){
		r2 = (s / (4.0 * pi));
		r = sqrt(r2);
		h2 = s * (s - 2 * pi * r2) / (pi * pi * r2);
		h = sqrt(h2);
		v = sqrt(pi * pi * r2 * r2 * h2) / 3.0;
		printf("%.2f\n%.2f\n%.2f\n", v, h, r);
	}

	return 0;
}
