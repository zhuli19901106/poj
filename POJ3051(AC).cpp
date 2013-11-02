#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXH = 1005;
const int MAXW = 85;
int a[MAXH][MAXW];
int b[MAXH][MAXW];
int w, h;
int res, max_res;
int dir[4][2] = {
	{-1, 0}, {+1, 0}, {0, -1}, {0, +1}
};

void dfs(int x, int y)
{
	int x1, y1;
	int i;

	b[x][y] = 1;
	++res;

	for(i = 0; i < 4; ++i){
		x1 = x + dir[i][0];
		y1 = y + dir[i][1];
		if(x1 < 1 || x1 > h || y1 < 1 || y1 > w){
			continue;
		}
		if(!a[x1][y1] || b[x1][y1]){
			continue;
		}
		dfs(x1, y1);
	}
}

int main()
{
	int i, j;
	char str[1000];

	while(scanf("%d%d", &w, &h) == 2){
		memset(a, 0, MAXH * MAXW * sizeof(int));
		memset(b, 0, MAXH * MAXW * sizeof(int));
		for(i = 1; i <= h; ++i){
			scanf("%s", str);
			for(j = 1; j <= w; ++j){
				a[i][j] = str[j - 1] == '*' ? 1 : 0;
			}
		}
		
		max_res = 0;
		for(i = 1; i <= h; ++i){
			for(j = 1; j <= w; ++j){
				if(!a[i][j] || b[i][j]){
					continue;
				}
				res = 0;
				dfs(i, j);
				max_res = res > max_res ? res : max_res;
			}
		}

		printf("%d\n", max_res);
	}

	return 0;
}

