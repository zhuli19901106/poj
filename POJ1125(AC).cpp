#include <cstdio>
using namespace std;

const int MAXN = 102;
int a[MAXN][MAXN];
int n;
const int INF = 1000000000;

int main()
{
	int i, j, k;
	int nk;
	int x, y;
	bool connected;
	int min_max_len, max_len, max_i;

	while (scanf("%d", &n) == 1 && n) {
		connected = false;

		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				a[i][j] = INF;
			}
		}
		
		for (i = 1; i <= n; ++i) {
			scanf("%d", &nk);
			for (j = 1; j <= nk; ++j) {
				scanf("%d%d", &x, &y);
				a[i][x] = y;
			}
		}
		
		for (k = 1; k <= n; ++k) {
			for (i = 1; i <= n; ++i) {
				if (a[i][k] >= INF) {
					continue;
				}
				for (j = 1; j <= n; ++j) {
					if (a[k][j] >= INF) {
						continue;
					}
					if (a[i][j] > a[i][k] + a[k][j]) {
						a[i][j] = a[i][k] + a[k][j];
					}
				}
			}
		}

		max_i = -1;
		min_max_len = INF;
		for (i = 1; i <= n; ++i) {
			max_len = -1;
			for (j = 1; j <= n; ++j) {
				if (i == j) {
					continue;
				}
				if (a[i][j] == INF) {
					break;
				} else if(a[i][j] > max_len) {
					max_len = a[i][j];
				}
			}
			if (j > n) {
				connected = true;
				if (max_len < min_max_len) {
					min_max_len = max_len;
					max_i = i;
				}
			}
		}

		if (connected) {
			printf("%d %d\n", max_i, min_max_len);
		} else {
			printf("disjoint\n");
		}
	}

	return 0;
}