#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[2000];
int sum, sum1;
int n;
int res;

bool comparator(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int t, ti;
	int i;

	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%d%d", &sum, &n);
			memset(a, 0, 2000 * sizeof(int));
			for(i = 0; i < n; ++i){
				scanf("%d", &a[i]);
			}
			sort(a, a + n, comparator);

			sum1 = 0;
			for(i = 0; i < n; ++i){
				sum1 += a[i];
				if(sum1 >= sum){
					break;
				}
			}

			printf("Scenario #%d:\n", ti);
			if(sum1 < sum){
				printf("impossible\n\n");
			}else{
				printf("%d\n\n", i + 1);
			}
		}
	}

	return 0;
}

