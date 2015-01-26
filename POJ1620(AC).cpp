#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
	double x;
	double y;
}st;
const int MAXN = 20;
st p[MAXN];
int a[MAXN];
int f[MAXN][MAXN];
int maxc;
int n;

double dist (const st &a, const st &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void dfs(int x)
{
	int i;
	int b[10];

	memset(b, 0, 10 * sizeof(int));
	for(i = 0; i < n; ++i){
		if(i == x){
			continue;
		}else{
			if(f[x][i] && a[i]){
				b[a[i]] = 1;
			}
		}
	}
	for(i = 1; i < 10; ++i){
		if(!b[i]){
			a[x] = i;
			if(i > maxc){
				maxc = i;
			}
			break;
		}
	}
	for(i = 0; i < n; ++i){
		if(f[x][i] && !a[i]){
			dfs(i);
		}
	}
}

int main()
{
	int i, j;
	int ti;

	ti = 0;
	while(scanf("%d", &n) == 1 && n){
		++ti;
		memset(p, 0, MAXN * sizeof(st));
		memset(a, 0, MAXN * sizeof(int));
		memset(f, 0, MAXN * MAXN * sizeof(int));
		for(i = 0; i < n; ++i){
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		for(i = 0; i < n; ++i){
			for(j = i + 1; j < n; ++j){
				if(dist(p[i], p[j]) <= 20){
					f[i][j] = f[j][i] = 1;
				}
			}
		}
		maxc = 0;
		memset(a, 0, MAXN * sizeof(int));
		for(i = 0; i < n; ++i){
			if(!a[i]){
				dfs(i);
			}
		}
		printf("The towers in case %d can be covered in %d frequencies.\n", ti, maxc);
	}

	return 0;
}
