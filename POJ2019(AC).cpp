#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int h[255][255];
int hmax[255][255];
int hmin[255][255];
int n, b, k;

typedef struct st{
	int x;
	int y;
	int h;
}st;

bool comparator(const st &a, const st &b)
{
	if(a.h == b.h){
		if(a.x == b.x){
			return a.y < b.y;
		}else{
			return a.x < b.x;
		}
	}else{
		return a.h < b.h;
	}
}

vector<st> vv;

int main()
{
	int i, j;
	int x, y;
	int n2;
	int c;
	int mx, my;
	st st_tmp;
	
	while(scanf("%d%d%d", &n, &b, &k) == 3){
		vv.clear();
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				scanf("%d", &h[i][j]);
				hmax[i][j] = -1;
				hmin[i][j] = -1;
				st_tmp.x = i;
				st_tmp.y = j;
				st_tmp.h = h[i][j];
				vv.push_back(st_tmp);
			}
		}
		sort(vv.begin(), vv.end(), comparator);
		n2 = n * n;
		c = n2;
		for(i = 0; i <= n2 - 1; ++i){
			if(c == 0){
				break;
			}
			for(mx = vv[i].x - b + 1; mx <= vv[i].x; ++mx){
				if(mx < 0 || mx > n - 1){
					continue;
				}
				for(my = vv[i].y - b + 1; my <= vv[i].y; ++my){
					if(my < 0 || my > n - 1){
						continue;
					}
					
					if(hmin[mx][my] == -1){
						hmin[mx][my] = vv[i].h;
						--c;
					}
				}
			}
		}
		
		c = n2;
		for(i = n2 - 1; i >= 0; --i){
			if(c == 0){
				break;
			}
			for(mx = vv[i].x - b + 1; mx <= vv[i].x; ++mx){
				if(mx < 0 || mx > n - 1){
					continue;
				}
				for(my = vv[i].y - b + 1; my <= vv[i].y; ++my){
					if(my < 0 || my > n - 1){
						continue;
					}
					
					if(hmax[mx][my] == -1){
						hmax[mx][my] = vv[i].h;
						--c;
					}
				}
			}
		}
		
		for(i = 0; i < k; ++i){
			scanf("%d%d", &x, &y);
			--x;
			--y;
			printf("%d\n", hmax[x][y] - hmin[x][y]);
		}
	}
	
	return 0;
}

