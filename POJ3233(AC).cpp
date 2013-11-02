#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 35;
int res[MAXN][MAXN];
int a[MAXN][MAXN];
int n, k, m;

void mat_mul(int n, int a[][MAXN], int b[][MAXN], int res[][MAXN], const int MOD)
{
	int i, j, k;

	if(a == NULL || b == NULL || res == NULL){
		return;
	}

	//memory overlapping is not tested, let's suppose they don't overlap.
	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			res[i][j] = 0;
			for(k = 0; k < n; ++k){
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
}

void mat_add(int n, int a[][MAXN], int b[][MAXN], int res[][MAXN], const int MOD)
{
	int i, j;

	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			res[i][j] = (a[i][j] + b[i][j]) % MOD;
		}
	}
}

void mat_pow(int n, int k, int a[][MAXN], int res[][MAXN], const int MOD)
{
	int i, j;
	int tmp[MAXN][MAXN];

	if(k == 0){
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				res[i][j] = (int)(i == j) % MOD;
			}
		}
	}else if(k & 1){
		mat_pow(n, k - 1, a, tmp, MOD);
		mat_mul(n, a, tmp, res, MOD);
	}else{
		mat_pow(n, k / 2, a, tmp, MOD);
		mat_mul(n, tmp, tmp, res, MOD);
	}
}

void series(int n, int k, int a[][MAXN], int res[][MAXN], const int MOD)
{
	int i, j;
	int tmp1[MAXN][MAXN];
	int tmp2[MAXN][MAXN];
	int mpow[MAXN][MAXN];

	if(k == 1){
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				res[i][j] = a[i][j];
			}
		}
	}else if(k & 1){
		series(n, k - 1, a, tmp1, MOD);
		mat_mul(n, tmp1, a, tmp2, MOD);
		mat_add(n, tmp2, a, res, MOD);
	}else{
		series(n, k / 2, a, tmp1, MOD);
		mat_pow(n, k / 2, a, mpow, MOD);
		mat_mul(n, tmp1, mpow, tmp2, MOD);
		mat_add(n, tmp1, tmp2, res, MOD);
	}
}

int main()
{
	int i, j;

	while(scanf("%d%d%d", &n, &k, &m) == 3){
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		series(n, k, a, res, m);

		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				printf((j ? " %d" : "%d"), res[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}

