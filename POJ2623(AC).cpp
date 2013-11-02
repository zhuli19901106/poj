#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 250005;
unsigned a[MAXN];
int n;

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		memset(a, 0, MAXN * sizeof(unsigned));
		for(i = 0; i < n; ++i){
			scanf("%u", &a[i]);
		}
		sort(a, a + n);
		if(n % 2){
			printf("%.1f\n", (double)a[(n - 1) / 2]);
		}else{
			printf("%.1f\n", (1.0 * a[n / 2 - 1] + a[n / 2]) * 0.5);
		}
	}

	return 0;
}

