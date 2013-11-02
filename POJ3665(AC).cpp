#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 1005;
int n, t;
int r[MAXN];

int main()
{
	int i;
	int ri, ti;

	while(scanf("%d%d", &n, &t) == 2){
		for(i = 1; i <= n; ++i){
			scanf("%d", &r[i]);
		}

		if(n == 1){
			for(ti = 1; ti <= t; ++ti){
				printf("1\n");
			}
			continue;
		}

		for(ti = 1; ti <= t; ++ti){
			ri = 1;
			for(i = 2; i <= n; ++i){
				if(r[i] > r[ri]){
					ri = i;
				}
			}
			printf("%d\n", ri);
			for(i = 1; i <= n; ++i){
				if(i == ri){
					continue;
				}
				r[i] += r[ri] / (n - 1);
			}
			r[ri] = r[ri] % (n - 1);
			for(i = 1; i <= n; ++i){
				if(r[ri] <= 0){
					break;
				}
				if(i == ri){
					continue;
				}
				--r[ri];
				++r[i];
			}
		}
	}

	return 0;
}

