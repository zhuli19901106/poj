#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, d, an, ad;
	double err;
	double f, t;
	int lim;

	while(scanf("%lf%d", &f, &lim) == 2){
		n = d = 1;
		an = n;
		ad = d;
		err = fabs(f - (double)n / d);
		while(n <= lim && d <= lim){
			t = (double)n / d - f;
			if(t >= 0){
				if(fabs(t) < err){
					err = fabs(t);
					an = n;
					ad = d;
				}
				++d;
			}else{
				if(fabs(t) < err){
					err = fabs(t);
					an = n;
					ad = d;
				}
				++n;
			}
		}
		printf("%d %d\n", an, ad);
	}

	return 0;
}

