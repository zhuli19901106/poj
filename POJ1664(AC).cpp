#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 11;
int f[MAXN][MAXN][MAXN];

int main()
{
	int i, j, k;
	int t, ti;
	int m, n;

	memset(f, 0, MAXN * MAXN * MAXN * sizeof(int));
	f[0][0][0] = 1;
	for(i = 1; i < MAXN; ++i){
		for(j = 0; j < MAXN; ++j){
			for(t = j; t < MAXN; ++t){
				for(k = 0; k + t < MAXN; ++k){
					f[i][t][k + t] += f[i - 1][j][k];
				}
			}
		}
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &m, &n);
			k = 0;
			for(i = 0; i < MAXN; ++i){
				k += f[n][i][m];
			}
			printf("%d\n", k);
		}
	}

	return 0;
}

