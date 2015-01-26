#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const double pi = 3.1415926535;

void myswap(double &a, double &b)
{
	double d;

	d = a;
	a = b;
	b = d;
}

int main()
{
	double s, d;
	double A, B, cosA, cosB;
	double res;
	double x1, x2, y1, y2, r1, r2;

	while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2) == 6){
		if(r1 < r2){
			myswap(x1, x2);
			myswap(y1, y2);
			myswap(r1, r2);
		}
		d = sqrt(1.0 * (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if(d >= r1 + r2){
			res = 0;
		}else if(d <= r1 - r2){
			res = pi * r2 * r2;
		}else{
			cosA = (r2 * r2 + d * d - r1 * r1) / (2.0 * r2 * d);
			cosB = (r1 * r1 + d * d - r2 * r2) / (2.0 * r1 * d);
			A = acos(cosA);
			B = acos(cosB);
			s = (r1 + r2 + d) / 2.0;
			s = sqrt(s * (s - r1) * (s - r2) * (s - d));
			res = r1 * r1 * B + r2 * r2 * A - 2 * s;
		}

		printf("%.3f\n", res);
	}

	return 0;
}
