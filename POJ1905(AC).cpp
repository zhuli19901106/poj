#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

double f(const double x, const double l0)
{
	return l0 * x / sin(x);
}

int main()
{
	double l0, n, c, l1;
	const double pi = 3.1415926;
	const double err = 1e-12;
	double high, mid, low, fmid;
	double r;
	
	while(scanf("%lf%lf%lf", &l0, &n, &c) == 3 && !(l0 < 0 && n < 0 && c < 0)){
		l1 = (1.0 + n * c) * l0;
		low = 0;
		high = pi / 2;
		while(high - low >= err){
			mid = (low + high) / 2.0;
			fmid = f(mid, l0);
			if(fmid >= l1){
				high = mid;
			}else if(fmid < l1){
				low = mid;
			}
		}
		r = l1 / (2.0 * mid);
		printf("%.3f\n", r - r * cos(mid));
	}
	
	return 0;
}
