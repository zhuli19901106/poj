#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

int res, max_res;
const int MAXN = 105;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int n, m, k;
const int dir[4][2] = {
	{-1, 0}, {+1, 0}, {0, -1}, {0, +1}
};

void dfs(int x, int y)
{
	int i;
	int x1, y1;

	++res;
	b[x][y] = 1;

	for(i = 0; i < 4; ++i){
		x1 = x + dir[i][0];
		y1 = y + dir[i][1];
		if(x1 < 1 || x1 > n || y1 < 1 || y1 > m){
			continue;
		}
		if(b[x1][y1] || !a[x1][y1]){
			continue;
		}
		
		dfs(x1, y1);
	}
}

int main()
{
	int i, j;
	int x, y;

	while(scanf("%d%d%d", &n, &m, &k) == 3){
		memset(a, 0, MAXN * MAXN * sizeof(int));
		memset(b, 0, MAXN * MAXN * sizeof(int));
		for(i = 0; i < k; ++i){
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		max_res = 0;
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= m; ++j){
				if(!b[i][j] && a[i][j]){
					res = 0;
					dfs(i, j);
					if(max_res < res){
						max_res = res;
					}
				}
			}
		}

		printf("%d\n", max_res);
	}

	return 0;
}

