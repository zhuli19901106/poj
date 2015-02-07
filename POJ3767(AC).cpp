#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 605;
int a[N][N];
int v[N];
int d[N];
int s[N];
int n;

int main()
{
	int i, j, k;
	int m, x, y, dist;
	int md;

	while (scanf("%d", &n) == 1 && n) {
		scanf("%d", &m);
		memset(a, -1, sizeof(a));
		for (i = 1; i <= m; ++i) {
			scanf("%d%d%d", &x, &y, &dist);
			a[x][y] = a[y][x] = dist;
		}
		for (i = 1; i <= n; ++i) {
			scanf("%d", &s[i]);
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (s[i] == 2 && s[j] == 1) {
					a[i][j] = -1;
				}
			}
		}
		
		// I call upon thee, mighty Dijkstra.
		memset(v, 0, sizeof(v));
		memset(d, -1, sizeof(v));
		
		d[1] = 0;
		k = 1;
		v[k] = 1;
		for (i = 1; i <= n - 1; ++i) {
			for (j = 1; j <= n; ++j) {
				if (v[j] || a[k][j] == -1) {
					continue;
				}
				if (d[j] == -1 || d[j] > d[k] + a[k][j]) {
					d[j] = d[k] + a[k][j];
				}
			}

			md = INT_MAX;
			for (j = 1; j <= n; ++j) {
				if (v[j] || d[j] == -1) {
					continue;
				}
				if (d[j] < md) {
					md = d[j];
					k = j;
				}
			}
			v[k] = 1;
		}
		printf("%d\n", d[2]);
	}

	return 0;
}