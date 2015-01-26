#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int a[1005];
int a1[1005];
typedef struct st{
	int a;
	int b;
	int d;
}st;

bool comparator(const st &a, const st &b)
{
	return a.d > b.d;
}

st v[1000005];
int n, m;
int p1[1005];
int pc1;
int p2[1005];
int pc2;
int res;
int f[1005][1005];

int find_root(int x)
{
	int k, r;

	r = x;
	while(r != a[r]){
		r = a[r];
	}

	k = x;
	while(x != r){
		x = a[x];
		a[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int t, ti;
	int i, j, cc;
	int ra, rb;

	scanf("%d", &t);
	for(ti = 1; ti <= t; ++ti){
		scanf("%d%d", &n, &m);
		memset(a, 0, 1005 * sizeof(int));
		memset(a1, 0, 1005 * sizeof(int));
		memset(f, 0, 1005 * 1005 * sizeof(int));
		memset(v, 0, 1000005 * sizeof(st));
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &v[i].a, &v[i].b, &v[i].d);
			f[v[i].a][v[i].b] = v[i].d;
			f[v[i].b][v[i].a] = v[i].d;
		}
		sort(v, v + m, comparator);

		for(i = 1; i <= n; ++i){
			a[i] = i;
			a1[i] = i;
		}

		cc = 0;
		res = 99999999;
		for(i = 0; i < m; ++i){
			if(find_root(1) == find_root(n)){
				break;
			}
			ra = find_root(v[i].a);
			rb = find_root(v[i].b);
			if(ra != rb){
				a[ra] = rb;
				a1[ra] = rb;
				find_root(v[i].a);
				find_root(v[i].b);
				if(v[i].d < res){
					res = v[i].d;
				}
				++cc;
			}
		}

		printf("Scenario #%d:\n%d\n\n", ti, res);
	}

	return 0;
}
