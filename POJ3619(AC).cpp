#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>

int n, k;
int s, t, r;
double res;

int main()
{
	int i;

	while(scanf("%d%d", &n, &k) == 2){
		for(i = 0; i <k; ++i){
			scanf("%d%d%d", &s, &t, &r);
			if(n % (s * t) == 0){
				res = n / (s * t) * (t + r) - r;
			}else{
				res = n / (s * t) * (t + r) + 1.0 * (n % (s * t)) / s;
			}
			printf("%d\n", int(ceil(res)));
		}
	}

	return 0;
}

