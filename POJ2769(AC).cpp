#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
const int MAXN = 305;
int a[MAXN];
int r[200000];

int main()
{
	int i;
	int t, ti;
	
	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			scanf("%d", &n);
			for (i = 0; i < n; ++i){
				scanf("%d", &a[i]);
			}
			if (n == 1) {
				printf("1\n");
				continue;
			}
			m = 2;
			while (true) {
				for (i = 0; i < m; ++i) {
					r[i] = 0;
				}
				for (i = 0; i < n; ++i) {
					if (r[a[i] % m]) {
						break;
					} else {
						r[a[i] % m] = 1;
					}
				}
				if (i == n) {
					printf("%d\n", m);
					break;
				} else {
					++m;
				}
			}
		}
	}

	return 0;
}