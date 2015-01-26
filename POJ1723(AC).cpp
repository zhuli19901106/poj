#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int x[10000];
int y[10000];
int n;
int res;

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%d%d", &x[i], &y[i]);
		}
		sort(x, x + n);
		sort(y, y + n);
		for(i = 0; i < n; ++i){
			x[i] -= i;
		}
		sort(x, x + n);
		res = 0;
		for(i = 0; i < n / 2; ++i){
			res += (x[n - 1 - i] - x[i] + y[n - 1 - i] - y[i]);
		}

		printf("%d\n", res);
	}

	return 0;
}
