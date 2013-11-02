#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1005;
double a[MAXN];
int n;
int f1[MAXN];
int f2[MAXN];
int ff1[MAXN];
int ff2[MAXN];

int mymax(const int &a, const int &b)
{
	return (a > b ? a : b);
}

int main()
{
	int i, j;
	int res;

	while(scanf("%d", &n) == 1){
		for(i = 1; i <= n; ++i){
			scanf("%lf", &a[i]);
		}
		memset(f1, 0, MAXN * sizeof(int));
		memset(f2, 0, MAXN * sizeof(int));
		f1[1] = 1;
		for(i = 2; i <= n; ++i){
			f1[i] = 1;
			for(j = 1; j < i; ++j){
				if(a[j] < a[i] && f1[j] + 1 > f1[i]){
					f1[i] = f1[j] + 1;
				}
			}
		}

		f2[n] = 1;
		for(i = n - 1; i >= 1; --i){
			f2[i] = 1;
			for(j = n; j > i; --j){
				if(a[j] < a[i] && f2[j] + 1 > f2[i]){
					f2[i] = f2[j] + 1;
				}
			}
		}

		ff1[1] = f1[1];
		for(i = 2; i <= n; ++i){
			ff1[i] = mymax(f1[i], ff1[i - 1]);
		}

		ff2[n] = f2[n];
		for(i = n - 1; i >= 1; --i){
			ff2[i] = mymax(f2[i], ff2[i + 1]);
		}

		res = ff1[1] + ff2[2];
		for(i = 2; i <= n - 1; ++i){
			if(ff1[i] + ff2[i + 1] > res){
				res = ff1[i] + ff2[i + 1];
			}
		}
		res = n - res;
		printf("%d\n", res);
	}

	return 0;
}

