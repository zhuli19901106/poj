#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[26][26];
int b[26][26];
int n, m;
int res;

void dfs(int x, int y, int cc)
{
	int i;

	if(cc > res){
		res = cc;
	}

	for(i = 0; i < n; ++i){
		if(i == x || i == y){
			continue;
		}
		if(a[y][i] && !b[y][i] && !b[i][y]){
			b[y][i] = 1;
			dfs(y, i, cc + 1);
			b[y][i] = 0;
		}
	}
}

int main()
{
	int i, j;
	int x, y;

	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		memset(a, 0, 26 * 26 * sizeof(int));
		memset(b, 0, 26 * 26 * sizeof(int));
		for(i = 0; i < m; ++i){
			scanf("%d%d", &x, &y);
			a[x][y] = a[y][x] = 1;
		}

		res = 0;
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				if(i == j || !a[i][j]){
					continue;
				}
				b[i][j] = 1;
				dfs(i, j, 1);
				b[i][j] = 0;
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
