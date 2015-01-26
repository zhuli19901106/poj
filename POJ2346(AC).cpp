#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[11];
int count;

void dfs(const int sum, const int n, int s, int cn)
{
	if(cn == n && s == sum){
		++count;
		return;
	}
	if(cn < n && s > sum){
		return;
	}

	if(cn == n - 1){
		if(sum - s >= 0 && sum - s <= 9){
			dfs(sum, n, sum, cn + 1);
			return;
		}else{
			return;
		}
	}
	if(s + (n - cn) * 9 < sum){
		return;
	}

	int i;
	for(i = 0; i <= 9; ++i){
		dfs(sum, n, s + i, cn + 1);
	}
}

int main()
{
	int n, i;

	memset(a, 0, 11 * sizeof(int));
	a[0] = 0;
	for(n = 2; n <= 10; n += 2){
		a[n] = 0;
		for(i = 0; i <= n / 2 * 9; ++i){
			count = 0;
			dfs(i, n / 2, 0, 0);
			a[n] += count * count;
		}
	}

	while(scanf("%d", &n) == 1){
		printf("%d\n", a[n]);
	}

	return 0;
}
