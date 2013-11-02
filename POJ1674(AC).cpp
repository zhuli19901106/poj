#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[10005];
int b[10005];
int n;

int main()
{
	int t, ti;
	int i, j;
	int res;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			for(i = 1; i <= n; ++i){
				scanf("%d", &a[i]);
			}
			memset(b, 0, 10005 * sizeof(int));
			res = n;
			for(i = 1; i <= n; ++i){
				if(b[i]){
					continue;
				}else{
					j = i;
					while(!b[j]){
						b[j] = 1;
						j = a[j];
					}
					--res;
				}
			}

			printf("%d\n", res);
		}
	}

	return 0;
}

