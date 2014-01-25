#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

void reverse(char s[], int left, int right)
{
	int i;
	char ch;

	if (NULL == s) {
		return;
	}

	if (left > right) {
		i = left;
		left = right;
		right = i;
	}

	i = left;
	while (i < left + right - i) {
		ch = s[i];
		s[i] = s[left + right - i];
		s[left + right - i] = ch;
		++i;
	}
}

int main()
{
	char s[205];
	char ch;
	int len;
	int i, j;

	while (scanf("%s", s) == 1) {
		len = strlen(s);
		sort(s, s + len);
		while (true) {
			printf("%s\n", s);
			for (i = len - 2; i >= 0; --i) {
				if (s[i] < s[i + 1]) {
					break;
				}
			}
			if (i < 0) {
				break;
			}

			j = len - 1;
			while (j > i && s[j] <= s[i]) {
				--j;
			}
			ch = s[i];
			s[i] = s[j];
			s[j] = ch;
			reverse(s, i + 1, len - 1);
		}
	}

	return 0;
}