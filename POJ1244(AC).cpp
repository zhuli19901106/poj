#include <cmath>
#include <cstdio>
using namespace std;

inline double dist(double x[2], double y[2])
{
	return sqrt(
		(x[0] - y[0]) * (x[0] - y[0]) + 
		(x[1] - y[1]) * (x[1] - y[1]));
}

int main()
{
	int i, j, k;
	int n, n2;
	char alpha[12][12];
	char s[100];
	double a[12][12][2];
	double d1, d2, d3;
	double p[100][2];
	int np;
	int cc;
	const double EPS = 1E-6;
	bool suc;

	while (scanf("%d", &n) == 1 && n) {
		n2 = n * (n + 1) / 2;
		scanf("%s", s);
		k = 0;
		for (i = 0; i < n; ++i) {
			for (j = 0; j <= i; ++j) {
				a[i][j][0] = sqrt(3.0) * i;
				a[i][j][1] = 2 * j - i;
				alpha[i][j] = s[k++];
			}
		}

		cc = 0;
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			np = 0;
			for (i = 0; i < n; ++i) {
				for (j = 0; j <= i; ++j) {
					if (alpha[i][j] == ch) {
						p[np][0] = a[i][j][0];
						p[np][1] = a[i][j][1];
						++np;
					}
				}
			}

			suc = false;
			for (i = 0; i < np; ++i) {
				for (j = i + 1; j < np; ++j) {
					for (k = j + 1; k < np; ++k) {
						d1 = dist(p[i], p[j]);
						d2 = dist(p[j], p[k]);
						d3 = dist(p[k], p[i]);
						if (
							(abs(d1 - d2) <= EPS) &&
							(abs(d2 - d3) <= EPS) &&
							(abs(d3 - d1) <= EPS)
						) {
							suc = true;
							putchar(ch);
							++cc;
						}
						if (suc) {
							break;
						}
					}
					if (suc) {
						break;
					}
				}
				if (suc) {
					break;
				}
			}
		}
		if (cc > 0) {
			printf("\n");
		} else {
			printf("LOOOOOOOOSER!\n");
		}
	}

	return 0;
}