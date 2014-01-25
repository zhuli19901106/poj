#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	const int MAXN = 100;
	int a[MAXN];
	char s[MAXN];
	int n;
	int i, ni;
	int len;

	// (O_o) single test case, no need to use while () {}
	if (scanf("%d", &n) == 1) {
		for (ni = 0; ni < n; ++ni) {
			memset(a, 0, MAXN * sizeof(int));
			memset(s, 0, MAXN * sizeof(char));
			scanf("%s", s);
			len = strlen(s);
			for (i = 0; i < len; ++i) {
				a[i] += (s[len - 1 - i] - '0');
			}
			scanf("%s", s);
			len = strlen(s);
			for (i = 0; i < len; ++i) {
				a[i] += (s[len - 1 - i] - '0');
			}
			for (i = 0; i < MAXN - 1; ++i) {
				a[i + 1] += a[i] / 2;
				a[i] %= 2;
			}
			a[MAXN - 1] %= 2;

			printf("%d ", ni + 1);
			i = MAXN - 1;
			while (i > 0 && a[i] == 0) {
				--i;
			}
			while (i >= 0) {
				putchar(a[i] + '0');
				--i;
			}
			putchar('\n');
		}
	}

	return 0;
}