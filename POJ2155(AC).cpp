#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1010;
int c[MAXN + 1][MAXN + 1];
int n;
int t, ti;

int low_bit(int x)
{
	return x & (-x);
}

void add_value(int x, int y, int v)
{
	int ix, iy;

	ix = x;
	while(ix > 0){
		iy = y;
		while(iy > 0){
			c[ix][iy] += v;
			iy -= low_bit(iy);
		}
		ix -= low_bit(ix);
	}
}

int get_sum(int x, int y, int n)
{
	int ix, iy;
	int sum;

	if(x <= 0 || y <= 0){
		return 0;
	}

	sum = 0;
	ix = x;
	while(ix <= n){
		iy = y;
		while(iy <= n){
			sum += c[ix][iy];
			iy += low_bit(iy);
		}
		ix += low_bit(ix);
	}

	return sum;
}

int main()
{
	int ncase, icase;
	char s[10];
	int x1, y1, x2, y2;

	while(scanf("%d", &ncase) == 1){
		for(icase = 0; icase < ncase; ++icase){
			if(icase > 0){
				printf("\n");
			}
			scanf("%d%d", &n, &t);
			memset(c, 0, (MAXN + 1) * (MAXN + 1) * sizeof(int));
			for(ti = 0; ti < t; ++ti){
				scanf("%s", s);
				if(s[0] == 'C'){
					scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
					add_value(x2, y2, 1);
					add_value(x1 - 1, y1 - 1, 1);
					add_value(x1 - 1, y2, -1);
					add_value(x2, y1 - 1, -1);
				}else if(s[0] == 'Q'){
					scanf("%d%d", &x1, &y1);
					printf("%d\n", get_sum(x1, y1, n) % 2);
				}
			}
		}
	}

	return 0;
}
