#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[50005];
int b[50005];
int n, m;
int res;

int find_root(int x)
{
	int k, r;

	r = x;
	while(r != a[r]){
		r = a[r];
	}

	k = x;
	while(x != a[x]){
		x = a[x];
		a[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int x, y;
	int rx, ry;
	int i;
	int ti;

	ti = 0;
	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		++ti;
		memset(a, 0, 50005 * sizeof(int));
		memset(b, 0, 50005 * sizeof(int));
		for(i = 1; i <= n; ++i){
			a[i] = i;
		}
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

		for(i = 1; i <= n; ++i){
			find_root(i);
		}

		res = 0;
		for(i = 1; i <= n; ++i){
			if(!b[a[i]]){
				b[a[i]] = 1;
				++res;
			}
		}

		printf("Case %d: %d\n", ti, res);
	}

	return 0;
}
