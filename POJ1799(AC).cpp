#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const double pi = 3.1415926;
int main()
{
	double R, r;
	int n;
	int t, ti;

	scanf("%d", &t);
	for(ti = 1; ti <= t; ++ti){
		scanf("%lf%d", &R, &n);
		r = R * sin(pi / n) / (1.0 + sin(pi / n));
		printf("Scenario #%d:\n%.3f\n\n", ti, r);
	}

	return 0;
}

