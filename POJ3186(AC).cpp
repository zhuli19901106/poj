#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[2005];
int f[2005][2005];
int n;

int max(const int a, const int b)
{
	return (a > b ? a : b);
}

int main()
{
	int i, j;

	while(scanf("%d", &n) == 1){
		memset(a, 0, 2005 * sizeof(int));
		memset(f, 0, 2005 * 2005 * sizeof(int));
		for(i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		for(i = 1; i <= n; ++i){
			f[i][i] = n * a[i];
		}
		for(i = 1; i <= n - 1; ++i){
			for(j = 1; i + j <= n; ++j){
				f[j][j + i] = max(f[j][j + i - 1] + a[j + i] * (n - i), a[j] * (n - i) + f[j + 1][j + i]);
			}
		}
		printf("%d\n", f[1][n]);
	}
	
	return 0;
}

