#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int res[1001];
int main()
{
	int i, j, k;
	int rt, n;
	int mina, a;
	int ti, t;

	memset(res, 0, 1001 * sizeof(int));
	for(n = 1; n <= 1000; ++n){
		rt = (int)sqrt(1.0 * n) + 1;
		mina = -1;
		for(i = 1; i <= rt; ++i){
			if(n % i){
				continue;
			}
			for(j = i; j <= rt; ++j){
				if((n / i) % j){
					continue;
				}else if((k = n / i / j) < j){
					continue;
				}else{
					a = 2 * (i * j + j * k + k * i);
					if(mina == -1 || a < mina){
						mina = a;
					}
				}
			}
		}
		res[n] = mina;
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			printf("%d\n", res[n]);
		}
	}

	return 0;
}

