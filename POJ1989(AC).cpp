#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 10005;
int a[MAXN];
int ac;
int n, k;

int main()
{
	int x;
	int i;
	int res;

	while(scanf("%d%d", &n, &k) == 2){
		memset(a, 0, MAXN * sizeof(int));
		ac = 0;
		res = 1;
		for(i = 0; i < n; ++i){
			scanf("%d", &x);
			if(!a[x]){
				a[x] = 1;
				++ac;
			}
			if(ac == k){
				memset(a, 0, MAXN * sizeof(int));
				ac = 0;
				++res;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}

