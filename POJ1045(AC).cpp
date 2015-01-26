#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double vs;
	double r;
	double c;
	double w;
	double r2;
	double vsr;
	double c2;
	int n, i;

	while(scanf("%lf%lf%lf", &vs, &r, &c) == 3){
		r2 = r * r;
		vsr = vs * r;
		c2 = c * c;
		
		scanf("%d", &n);
		for(i = 0; i < n; ++i){
			scanf("%lf", &w);
			printf("%.3f\n", vsr / sqrt(r2 + 1.0 / (w * w * c2)));
		}
	}
	
	return 0;
}
