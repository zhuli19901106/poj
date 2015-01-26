#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 105;
char a[MAXN][MAXN];
int b[MAXN][MAXN];
int n, m;
int cc, res;
int dx[8] = {-1,-1,-1, 0, 0,+1,+1,+1};
int dy[8] = {-1, 0,+1,-1,+1,-1, 0,+1};

void dfs(int x, int y)
{
	int i;

	b[x][y] = 1;
	--cc;
	for(i = 0; i < 8; ++i){
		if(!b[x + dx[i]][y + dy[i]] && a[x + dx[i]][y + dy[i]] == 'W'){
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main()
{
	int i, j;
	char s[500];

	while(scanf("%d%d", &n, &m) == 2){
		memset(a, '.', MAXN * MAXN * sizeof(char));
		cc = 0;
		for(i = 1; i <= n; ++i){
			scanf("%s", s);
			for(j = 1; j <= m; ++j){
				a[i][j] = s[j - 1];
				if(a[i][j] == 'W'){
					++cc;
				}
			}
		}
		memset(b, 0, MAXN * MAXN * sizeof(int));

		res = 0;
		while(cc > 0){
			for(i = 1; i <= n; ++i){
				for(j = 1; j <= m; ++j){
					if(a[i][j] == 'W' && !b[i][j]){
						dfs(i, j);
						++res;
					}
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
