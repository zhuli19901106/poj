// Don't use STL map, use hashing to ensure your program runs fast.
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 1005;
int b[MAXN];
int prime[300];
int pc;
const int MAXK = 105;
int x[MAXK];
int y[MAXK];
int facx[MAXK][10][2];
int facy[MAXK][10][2];
int fcx[MAXK];
int fcy[MAXK];
int n, m, k;
int fc;
int mm[MAXN];
vector<int> res;

int main()
{
	int i, j;
	int tmp;
	int cc;

	memset(b, 0, MAXN * sizeof(int));
	b[0] = b[1] = 1;
	for (i = 2; i * i <= 1000; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; i * j <= 1000; ++j) {
			b[i * j] = 1;
		}
	}

	pc = 0;
	for (i = 0; i <= 1000; ++i) {
		b[i] = !b[i];
		if (b[i]) {
			prime[pc++] = i;
		}
	}

	while (scanf("%d", &m) == 1 && m) {
		scanf("%d%d", &n, &k);
		res.clear();
		memset(facx, 0, MAXK * 10 * 2 * sizeof(int));
		memset(facy, 0, MAXK * 10 * 2 * sizeof(int));
		memset(fcx, 0, MAXK * sizeof(int));
		memset(fcy, 0, MAXK * sizeof(int));
		for (i = 0; i < k; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			tmp = x[i];

			j = 0;
			fcx[i] = 0;
			while (prime[j] * prime[j] <= tmp) {
				if (tmp % prime[j] == 0) {
					facx[i][fcx[i]][0] = prime[j];
					facx[i][fcx[i]][1] = 0;
					while (tmp % prime[j] == 0) {
						++facx[i][fcx[i]][1];
						tmp /= prime[j];
					}
					++fcx[i];
				}
				++j;
			}
			if (tmp > 1) {
				facx[i][fcx[i]][0] = tmp;
				facx[i][fcx[i]][1] = 1;
				++fcx[i];
				tmp = 1;
			}

			tmp = y[i];
			j = 0;
			fcy[i] = 0;
			while (prime[j] * prime[j] <= tmp) {
				if (tmp % prime[j] == 0) {
					facy[i][fcy[i]][0] = prime[j];
					facy[i][fcy[i]][1] = 0;
					while (tmp % prime[j] == 0) {
						++facy[i][fcy[i]][1];
						tmp /= prime[j];
					}
					++fcy[i];
				}
				++j;
			}
			if (tmp > 1) {
				facy[i][fcy[i]][0] = tmp;
				facy[i][fcy[i]][1] = 1;
				++fcy[i];
				tmp = 1;
			}
		}

		memset(mm, 0, MAXK * sizeof(int));
		fc = 0;
		tmp = n;
		j = 0;
		while (prime[j] * prime[j] <= tmp) {
			if (tmp % prime[j] == 0) {
				cc = 0;
				while (tmp % prime[j] == 0) {
					++cc;
					tmp /= prime[j];
				}
				mm[prime[j]] = cc;
				++fc;
			}
			++j;
		}
		if (tmp > 1) {
			mm[tmp] = 1;
			++fc;
			tmp = 1;
		}

		cc = 0;
		int round = 0;
		while (true) {
			if (fc == 0) {
				res.push_back(0);
				++cc;
			}else if(fc == 1 && mm[2] > 0) {
				res.push_back(mm[2]);
				++cc;
			}
			if (cc >= m) {
				//printf("round = %d\n", round);
				break;
			}
			for (i = 0; i < k; ++i) {
				for (j = 0; j < fcy[i]; ++j) {
					if (mm[facy[i][j][0]] < facy[i][j][1]) {
						break;
					}
				}
				if (j == fcy[i]) {
					// there exists an f, such that n * f is still integral.
					for (j = 0; j < fcy[i]; ++j) {
						if (mm[facy[i][j][0]] > facy[i][j][1]) {
							mm[facy[i][j][0]] -= facy[i][j][1];
						} else {
							mm[facy[i][j][0]] = 0;
							--fc;
						}
					}
					for (j = 0; j < fcx[i]; ++j) {
						if (mm[facx[i][j][0]] > 0) {
							mm[facx[i][j][0]] += facx[i][j][1];
						} else {
							mm[facx[i][j][0]] = facx[i][j][1];
							++fc;
						}
					}
					break;
				}
			}
			if (i == k) {
				// the sequence ends here.
				break;
			}
			++round;
		}
		for (i = 0; i < (int)res.size(); ++i) {
			if (i > 0) {
				printf(" %d", res[i]);
			} else {
				printf("%d", res[i]);
			}
		}
		printf("\n");
	}

	return 0;
}