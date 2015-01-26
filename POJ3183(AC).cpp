#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 60005;
int a[MAXN];
int n;

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		memset(a, 0, MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		for(i = 1; i <= n; ++i){
			if(a[i] >= a[i - 1] && a[i] >= a[i + 1]){
				printf("%d\n", i);
			}
		}
	}

	return 0;
}
