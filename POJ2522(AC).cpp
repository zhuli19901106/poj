#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
LL a[222][11][222];
int c[20];
int m, n, n0;
LL k;

int main()
{
	int i, j, p;
	int t, ti, last_i;

	memset(a, 0, 222 * 11 * 222 * sizeof(LL));
	for(i = 1; i <= 220; ++i){
		a[i][1][i] = 1;
	}

	for(n = 2; n <= 10; ++n){
		for(m = 2; m <= 220; ++m){
			for(p = 1; p < m; ++p){
				for(j = p; j <= m - p; ++j){
					a[m][n][p] += a[m - p][n - 1][j];
				}
			}
		}
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d%lld", &m, &n, &k);
			n0 = n;
			last_i = 1;
			while(n > 0){
				i = last_i;
				while(k > a[m][n][i]){
					k = k - a[m][n][i];
					++i;
				}
				last_i = c[n] = i;
				--n;
				m = m - i;
			}

			for(i = n0; i >= 1; --i){
				printf("%d\n", c[i]);
			}
		}
	}

	return 0;
}

