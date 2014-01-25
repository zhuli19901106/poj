#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double x, y;
	int xx, yy;
	int n, m;
	int u, d;
	int i;
	int res, mres;
	const int INF = 1000000000;

	while (scanf("%d%d", &n, &m) == 2) {
		mres = INF;
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &u, &d);
			// accurate solution
			x = 1.0 * d * n / (u + d);
			y = 1.0 * u * n / (u + d);
			// approximated solution
			xx = (int)x + 1;
			yy = n - xx;
			res = xx * u - yy * d;
			if (res < mres) {
				mres = res;
			}
		}
		printf("%d\n", mres);
	}

	return 0;
}