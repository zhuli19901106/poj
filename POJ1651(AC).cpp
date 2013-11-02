#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[105];
int f[105][105];
int n;

int main()
{
	int i, j, k;
	int tmp;

	while(scanf("%d", &n) == 1){
		memset(a, 0, 105 * sizeof(int));
		memset(f, 0, 105 * 105 * sizeof(int));
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}

		for(i = 1; i <= n - 2; ++i){
			f[i][i + 1] = a[i - 1] * a[i] * a[i + 1];
		}
		for(i = 2; i <= n - 2; ++i){
			for(j = 1; j + i <= n - 1; ++j){
				f[j][j + i] = 999999999;
				for(k = j; k <= j + i - 1; ++k){
					//f[j][k] + f[k][j + i] + () * () * ()
					tmp = f[j][k] + a[j - 1] * a[k] * a[j + i] + f[k + 1][j + i];
					if(tmp < f[j][j + i]){
						f[j][j + i] = tmp;
					}
				}
			}
		}

		printf("%d\n", f[1][n - 1]);
	}

	return 0;
}

