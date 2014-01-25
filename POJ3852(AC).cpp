#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

vector<string> vs;
int n;
char s[105];
int res;

bool comparator(const string &x, const string &y)
{
	if (x.length() == y.length()) {
		return x < y;
	} else {
		return x.length() < y.length();
	}
}

int main()
{
	int i, j;
	int len;
	char ch;

	while (scanf("%d", &n) == 1 && n) {
		vs.clear();
		for (i = 0; i < n; ++i) {
			scanf("%s", s);
			len = strlen(s);
			for (j = 0; j < len - 1 - j; ++j) {
				ch = s[j];
				s[j] = s[len - 1 - j];
				s[len - 1 - j] = ch;
			}
			vs.push_back(string(s));
		}
		sort(vs.begin(), vs.end(), comparator);

		res = vs[0].length() - 1;
		for (i = 0; i < n - 1; ++i) {
			if (vs[i].length() == vs[i + 1].length()) {
				len = vs[i].length();
				for (j = 0; j < len; ++j) {
					if (vs[i][j] != vs[i + 1][j]) {
						break;
					}
				}
				if (len - j - 1 < res) {
					res = len - j - 1;
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}