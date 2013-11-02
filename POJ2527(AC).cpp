#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[10005];
int n, k;

int main()
{
	int i;

	while(scanf("%d%d", &n, &k) == 2 && !(n == -1 && k == -1)){
		memset(a, 0, 10005 * sizeof(int));
		for(i = 0; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		if(k == 0){
			printf("0\n");
			continue;
		}

		i = n;
		while(i - k >= 0){
			a[i - k] -= a[i];
			a[i] = 0;
			--i;
		}
		
		while(n >= 0 && a[n] == 0){
			--n;
		}
		if(n < 0){
			printf("0\n");
		}else{
			for(i = 0; i <= n; ++i){
				if(i == 0){
					printf("%d", a[i]);
				}else{
					printf(" %d", a[i]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}

