#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 50005;
int a[MAXN], n;
int res, ri;

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		memset(a, 0, MAXN * sizeof(int));
		a[1] = 0;
		for(i = 2; i <= n; ++i){
			scanf("%d", &a[i]);
		}

		res = 0x7fffffff;
		ri = -1;
		for(i = n - 2; i > 1; --i){
			if(a[i + 1] - a[1] + a[n] - a[i] < res){
				res = a[i + 1] - a[1] + a[n] - a[i];
				ri = i;
			}
		}

		if(res == 0x7fffffff){
			printf("0\n");
		}else{
			printf("%d\n", res);
			printf("%d %d %d %d\n", ri + 1, 1, n, ri);
		}
	}

	return 0;
}

