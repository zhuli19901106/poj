#include <cstdio>
using namespace std;

inline int myabs(const int &a)
{
	return (a >= 0 ? a : -a);
}

int main()
{
	int case_count;
	int n;
	int tmp;
	int even, odd;
	int ci, i;
	bool success;

	while (scanf("%d", &case_count) == 1) {
		for (ci = 0; ci < case_count; ++ci) {
			scanf("%d", &n);
			even = odd = 0;
			success = false;
			for (i = 0; i < n; ++i) {
				scanf("%d", &tmp);
				if (tmp) {
					if (i % 2) {
						++odd;
					} else {
						++even;
					}
				}
			}

			if (n % 2) {
				success = true;
			} else {
				if (myabs(odd - even) < 2) {
					success = true;
				} else {
					success = false;
				}
			}
			if (success) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}

	return 0;
}