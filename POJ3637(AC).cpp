#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;


int comp(const void *a, const void *b)
{
	return *(const int *)b - *(const int *)a;
}

int main()
{
	int sum;
	int a[20005];
	int n;
	int i;
	int t, ti;
	
	while(true){
		if(scanf("%d", &t) != 1){
			break;
		}
		
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%d", &a[i]);
			}
			qsort(a, n, sizeof(int), comp);
			sum = 0;
			for(i = 2; i < n; i += 3){
				sum += a[i];
			}
			printf("%d\n", sum);
		}
	}
	
	return 0;
}

