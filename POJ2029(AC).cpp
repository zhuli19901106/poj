#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 105;
int a[MAXN][MAXN];
int ps[MAXN][MAXN];
int w, h;
int s, t;
int sum[MAXN][MAXN];
int res;
int n;

int main()
{
	int i, j;
	int x, y;

	while(scanf("%d", &n) == 1 && n){
		scanf("%d%d", &w, &h);
		memset(a, 0, MAXN * MAXN * sizeof(int));
		memset(ps, 0, MAXN * MAXN * sizeof(int));
		memset(sum, 0, MAXN * MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		scanf("%d%d", &s, &t);

		for(i = 1; i <= w; ++i){
			for(j = 1; j <= h; ++j){
				ps[i][j] = ps[i][j - 1] + ps[i - 1][j] + a[i][j] - ps[i - 1][j - 1];
			}
		}

		for(i = s; i <= w; ++i){
			for(j = t; j <= h; ++j){
				sum[i][j] = ps[i][j] + ps[i - s][j - t] - ps[i][j - t] - ps[i - s][j];
			}
		}

		res = sum[s][t];
		for(i = s; i <= w; ++i){
			for(j = t; j <= h; ++j){
				if(sum[i][j] > res){
					res = sum[i][j];
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
