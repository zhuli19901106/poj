#include <cstdio>
using namespace std;

const int MAXN = 1005;
int a[MAXN][MAXN];
int n, s;
int cy_len;

int main()
{
	int i, j;

	while (scanf("%d%d", &n, &s) == 2) {
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[0][i]);
		}
		cy_len = 1;
		while (true) {
			for (i = 1; i <= n; ++i) {
				a[cy_len][i] = a[cy_len - 1][a[cy_len - 1][i]];
			}
			for (i = 1; i <= n; ++i) {
				if (a[cy_len][i] != a[0][i]) {
					break;
				}
			}
			if (i > n) {
				break;
			} else {
				++cy_len;
			}
		}
		for (i = 1; i <= n; ++i) {
			printf("%d\n", a[cy_len - s % cy_len][i]);
		}
	}

	return 0;
}