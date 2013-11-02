#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, k;
int a[1024];

void next_perm(int a[], int n)
{
	int p, i;

	for(p = n - 1; p > 0; --p){
		if(a[p] > a[p - 1]){
			for(i = n - 1; i > 0; --i){
				if(a[i] > a[p - 1]){
					break;
				}
			}
			swap(a[i], a[p - 1]);
			break;
		}
	}
	sort(a + p, a + n);
}

int main()
{
	int t, ti;
	int i;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &n, &k);
			for(i = 0; i < n; ++i){
				scanf("%d", &a[i]);
			}
			for(i = 0; i < k; ++i){
				next_perm(a, n);
			}

			for(i = 0; i < n; ++i){
				if(i == 0){
					printf("%d", a[i]);
				}else{
					printf(" %d", a[i]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}

