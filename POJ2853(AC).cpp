#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	long long int d;
	int n, ni;
	int i, j, rt;
	int res;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d%lld", &ni, &d);
			d *= 2;
			rt = (int)sqrt(1.0 * d);
			res = 0;
			for (j = 2; j <= rt; ++j) {
				if (d % j == 0 && (d / j - j + 1) % 2 == 0) {
					++res;
				}
			}
			printf("%d %d\n", ni, res);
		}
	}

	return 0;
}