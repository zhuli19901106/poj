#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
	int x;
	int y;
}st;

bool comparator(const st &a, const st &b)
{
	if(a.x == b.x){
		return a.y < b.y;
	}else{
		return a.x < b.x;
	}
}

st res[30];
int rc;
int a[30][30];
int r, c;
bool suc;
int cc;
int d[8][2] = {{-2, -1}, {-2, +1}, {-1, -2}, {-1, +2}, {+1, -2}, {+1, +2}, {+2, -1}, {+2, +1}};

void dfs(int x, int y)
{
	int i;
	int x1, y1;
	st p[8];
	int pc;

	if(suc){
		return;
	}

	if(cc == 0){
		for(i = 0; i < rc; ++i){
			printf("%c%d", res[i].x - 1 + 'A', res[i].y);
		}
		printf("\n");
		suc = true;
		return;
	}

	pc = 0;
	for(i = 0; i < 8; ++i){
		x1 = x + d[i][0];
		y1 = y + d[i][1];
		if(x1 >= 1 && x1 <= r && y1 >= 1 && y1 <= c && !a[x1][y1]){
			p[pc].x = x1;
			p[pc].y = y1;
			++pc;
		}
	}

	sort(p, p + pc, comparator);
	for(i = 0; i < pc; ++i){
		a[p[i].x][p[i].y] = 1;
		--cc;
		res[rc++] = p[i];
		dfs(p[i].x, p[i].y);
		--rc;
		++cc;
		a[p[i].x][p[i].y] = 0;
	}
}

int main()
{
	int n, ni;
	int i, j;

	while(scanf("%d", &n) == 1){
		for(ni = 1; ni <= n; ++ni){
			scanf("%d%d", &r, &c);
			printf("Scenario #%d:\n", ni);
			i = r;
			r = c;
			c = i;
			suc = false;
			for(i = 1; i <= r; ++i){
				for(j = 1; j <= c; ++j){
					rc = 0;
					memset(a, 0, 30 * 30 * sizeof(int));
					cc = r * c;

					a[i][j] = 1;
					--cc;
					res[rc].x = i;
					res[rc].y = j;
					++rc;
					dfs(i, j);
					--rc;
					++cc;
					a[i][j] = 0;

					if(suc){
						break;
					}
				}
				if(suc){
					break;
				}
			}

			if(!suc){
				printf("impossible\n");
			}

			printf("\n");
		}
	}

	return 0;
}

