#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 100005;
int a[MAXN];
int n, s;
int left, right;
int sum, len;

int main()
{
	int t, ti;
	int i;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &n, &s);
			memset(a, 0, MAXN * sizeof(int));

			sum = 0;
			for(i = 0; i < n; ++i){
				scanf("%d", &a[i]);
				sum += a[i];
			}

			if(sum < s){
				printf("0\n");
				continue;
			}

			left = 0;
			right = 0;
			sum = a[0];
			len = n + 1;
			while(right < n){
				if(sum >= s){
					if(right - left + 1 < len){
						len = right - left + 1;
					}
					sum -= a[left];
					++left;
				}else{
					++right;
					sum += a[right];
				}
			}
			printf("%d\n", len);
		}
	}

	return 0;
}
