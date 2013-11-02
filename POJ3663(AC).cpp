#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 20005;
int n, s, res;
int a[MAXN];

int main()
{
	int i;
	int big_half;
	int *ptr;

	while(scanf("%d%d", &n, &s) == 2){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}

		sort(a, a + n);
		if(a[0] + a[1] > s){
			printf("0\n");
			continue;
		}
		if(a[n - 2] + a[n - 1] <= s){
			printf("%d\n", n * (n - 1) / 2);
			continue;
		}

		res = 0;
		big_half = (s + 1) / 2;
		for(i = n - 1; i >= 0; --i){
			if(a[i] + a[0] > s){
				continue;
			}
			ptr = upper_bound(a, a + i, s - a[i]);
			res += ptr - a;
		}

		printf("%d\n", res);
	}

	return 0;
}

