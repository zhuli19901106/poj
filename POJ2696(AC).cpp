#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int ff[1005];
int bb[1005];
int a, b, c, d, e, f, g, h, n;

inline int mod(const int &a, const int &b)
{
	return a > 0 ? a % b : (b - (-a) % b) % b;
}

int fun(int x)
{
	if(bb[x]){
		return ff[x];
	}else{
		if(x & 0x1){
			ff[x] = mod(d * fun(x - 1) + e * fun(x - 2) - f * fun(x - 3), g);
			bb[x] = 1;
			return ff[x];
		}else{
			ff[x] = mod(f * fun(x - 1) - d * fun(x - 2) + e * fun(x - 3), h);
			bb[x] = 1;
			return ff[x];
		}
	}
}

int main()
{
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &n);
			memset(ff, 0, 1005 * sizeof(int));
			memset(bb, 0, 1005 * sizeof(int));
			ff[0] = a;
			ff[1] = b;
			ff[2] = c;
			bb[0] = bb[1] = bb[2] = 1;
			printf("%d\n", fun(n));
		}
	}

	return 0;
}

