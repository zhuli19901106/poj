#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
	int c1;
	int c2;
	int idx;
}st;
st a[50005];
int n, k;

bool cmp1(const st &x, const st &y)
{
	return x.c1 > y.c1;
}

bool cmp2(const st &x, const st &y)
{
	return x.c2 > y.c2;
}

int main()
{
	int i;

	while(scanf("%d%d", &n, &k) == 2){
		for(i = 1; i <= n; ++i){
			a[i].idx = i;
			scanf("%d%d", &a[i].c1, &a[i].c2);
		}
		sort(a + 1, a + n + 1, cmp1);
		sort(a + 1, a + k + 1, cmp2);
		printf("%d\n", a[1].idx);
	}

	return 0;
}

