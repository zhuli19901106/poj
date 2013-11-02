#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 20005;
int a[MAXN];
int n, s;
int res, count;

int main()
{
	int i;

	while(scanf("%d%d", &n, &s) == 2){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		::count = res = 0;
		for(i = n - 1; i >= 0; --i){
			res += a[i];
			++::count;
			if(res >= s){
				break;
			}
		}
		printf("%d\n", ::count);
	}

	return 0;
}

