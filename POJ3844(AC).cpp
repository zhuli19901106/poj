#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 50005;
int a[MAXN];
int sum[MAXN];
const int MAXD = 1000005;
int r[MAXD];
int c, ci;
int d, n;
long long int res;

int main()
{
	int i;

	while (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d%d", &d, &n);
			for (i = 0; i < n; ++i) {
				scanf("%d", &a[i]);
				a[i] = a[i] % d;
				sum[i] = 0;
			}
			memset(r, 0, MAXD * sizeof(int));
			sum[0] = a[0];
			for (i = 1; i < n; ++i) {
				sum[i] = (sum[i - 1] + a[i]) % d;
			}

			++r[0];
			for (i = 0; i < n; ++i) {
				++r[sum[i]];
			}

			res = 0;
			for (i = 0; i < d; ++i) {
				if (r[i] >= 2) {
					res += 1LL * r[i] * (r[i] - 1) / 2;
				}
			}

			printf("%lld\n", res);
		}
	}

	return 0;
}