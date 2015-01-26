#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a[30005];
	int n;
	int res;
	int i, greater;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%d", &a[i]);
			}

			if(n == 0){
				printf("0\n");
				continue;
			}

			res = 1;
			greater = 1;
			for(i = 1; i < n; ++i){
				if(greater){
					if(a[i] < a[i - 1]){
						greater = 0;
						++res;
					}
				}else{
					if(a[i] > a[i - 1]){
						greater = 1;
						++res;
					}
				}
			}

			printf("%d\n", res);
		}
	}

	return 0;
}
