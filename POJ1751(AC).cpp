#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 751;
int p[MAXN][2];
int a[MAXN];
int b0[MAXN];
int n, m;

int find_root(int x)
{
	int k, r;

	r = x;
	while(r != a[r]){
		r = a[r];
	}

	k = x;
	while(k != r){
		x = a[x];
		a[k] = r;
		k = x;
	}

	return r;
}

typedef struct st{
public:
	int a;
	int b;
	int d2;

	st(const int _a = 0, const int _b = 0, const int _d2 = 0)
	{
		a = _a;
		b = _b;
		d2 = _d2;
	}
}st;
vector<st> v;

bool comparator(const st &a, const st &b)
{
	return a.d2 < b.d2;
}

int main()
{
	int i, j;
	int x, y;
	int rx, ry;

	if(scanf("%d", &n) == 1){
		memset(a, 0, MAXN * sizeof(int));
		memset(p, 0, MAXN * 2 * sizeof(int));

		for(i = 1; i <= n; ++i){
			scanf("%d%d", &p[i][0], &p[i][1]);
			a[i] = i;
		}
		scanf("%d", &m);
		for(i = 1; i <= m; ++i){
			scanf("%d%d", &x, &y);
			rx = find_root(x);
			ry = find_root(y);
			if(rx != ry){
				a[rx] = ry;
				find_root(x);
				find_root(y);
			}
		}

		m = 0;
		memset(b0, 0, MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			a[i] = find_root(i);
			b0[a[i]] = 1;
		}

		for(i = 1; i <= n; ++i){
			if(b0[i]){
				++m;
			}
		}
		--m;

		v.clear();
		for(i = 1; i < n; ++i){
			for(j = i + 1; j <= n; ++j){
				if(a[i] != a[j]){
					v.push_back(st(i, j, (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1])));
				}
			}
		}
		sort(v.begin(), v.end(), comparator);

		for(i = 0; i < (int)v.size(); ++i){
			if(m <= 0){
				break;
			}
			rx = find_root(v[i].a);
			ry = find_root(v[i].b);
			if(rx != ry){
				a[rx] = ry;
				find_root(v[i].a);
				find_root(v[i].b);
				printf("%d %d\n", v[i].a, v[i].b);
				--m;
			}
		}
	}

	return 0;
}
