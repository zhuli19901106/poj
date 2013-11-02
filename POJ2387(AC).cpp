#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1005;
const int INF = 2147483647;
int t, n;
int v[MAXN];
int b[MAXN];
int a[MAXN][MAXN];

int main()
{
	int i, j;
	int x, y, dist;
	int min_v, min_i;

	while(scanf("%d%d", &t, &n) == 2){
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				a[i][j] = INF;
			}
		}

		for(i = 1; i <= t; ++i){
			scanf("%d%d%d", &x, &y, &dist);
			if(a[x][y] < 0 || a[x][y] > dist){
				a[x][y] = a[y][x] = dist;
			}
		}

		memset(b, 0, MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			b[i] = 0;
			v[i] = a[1][i];
		}

		b[1] = 1;
		v[1] = 0;

		for(i = 2; i <= n; ++i){
			min_v = INF;
			for(j = 1; j <= n; ++j){
				if(!b[j] && v[j] < min_v){
					min_i = j;
					min_v = v[j];
				}
			}
			b[min_i] = 1;

			for(j = 1; j <= n; ++j){
				if(!b[j] && a[min_i][j] < INF && (min_v + a[min_i][j] < v[j])){
					v[j] = min_v + a[min_i][j];
				}
			}
		}

		printf("%d\n", v[n]);
	}

	return 0;
}

