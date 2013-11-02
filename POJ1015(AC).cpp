#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int f[21][805];
int b[21][805];
int n, m;
int d[201];
int p[201];
int c[201];

int main()
{
	int i, j, k;
	int pp, qq;
	int off;
	int ti;

	ti = 0;
	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		++ti;
		for(i = 1; i <= n; ++i){
			scanf("%d%d", &d[i], &p[i]);
		}
		memset(f, -1, 21 * 805 * sizeof(int));
		memset(b, 0, 21 * 805 * sizeof(int));
		off = m * 20;
		f[0][off] = 0;
		for(i = 0; i < m; ++i){
			//i for number of juries chosen
			for(j = 0; j <= 2 * off; ++j){
				//j for |sum(p) - sum(d)|
				if(f[i][j] < 0){
					continue;
				}
				for(k = 1; k <= n; ++k){
					//k for n candidates
					if(f[i][j] + p[k] + d[k] > f[i + 1][j + p[k] - d[k]]){
						pp = i;
						qq = j;
						while(pp > 0 && b[pp][qq] != k){
							qq -= p[b[pp][qq]] - d[b[pp][qq]];
							--pp;
						}

						if(pp == 0){
							f[i + 1][j + p[k] - d[k]] = f[i][j] + p[k] + d[k];
							b[i + 1][j + p[k] - d[k]] = k;
						}
					}
				}
			}
		}

		i = off;
		j = 0;
		while(f[m][i + j] < 0 && f[m][i - j] < 0){
			++j;
		}

		if(f[m][i + j] > f[m][i - j]){
			k = i + j;
		}else{
			k = i - j;
		}

		printf("Jury #%d\n", ti);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", (f[m][k] - k + off) / 2, (f[m][k] + k - off) / 2);
		for(i = 0; i < m; ++i){
			c[i] = b[m - i][k];
			k -= p[c[i]] - d[c[i]];
		}
		sort(c, c + m);
		for(i = 0; i < m; ++i){
			printf(" %d", c[i]);
		}
		printf("\n\n");
	}

	return 0;
}

