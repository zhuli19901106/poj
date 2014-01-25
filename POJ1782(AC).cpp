#include <cstdio>
#include <cstring>
using namespace std;

char s[10005];

int main()
{
	int i, j;
	int ll, rr;
	int len;

	while (gets(s) != NULL) {
		len = strlen(s);
		if (len <= 0) {
			printf("\n");
			continue;
		}
		i = 0;
		while (i < len) {
			ll = i;
			rr = i + 1;
			while (rr < len && s[rr] != s[rr - 1]) {
				++rr;
			}
			if (rr == len) {
				// no repeated chracters till the end
				putchar('1');
				while (ll < rr) {
					if (s[ll] == '1') {
						putchar('1');
					}
					putchar(s[ll]);
					++ll;
				}
				putchar('1');
				i = rr;
				continue;
			} else {
				--rr;
				if (ll < rr) {
					putchar('1');
					while (ll < rr) {
						if (s[ll] == '1') {
							putchar('1');
						}
						putchar(s[ll]);
						++ll;
					}
					putchar('1');
					i = rr;
				}
			}
			j = i + 1;
			while (j < len && j - i < 9 && s[j] == s[i]) {
				++j;
			}
			printf("%d%c", j - i, s[i]);
			i = j;
		}
		printf("\n");
	}

	return 0;
}