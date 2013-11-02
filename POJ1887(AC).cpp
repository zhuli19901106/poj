#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[100000];
int b[100000];
int n, res;

int LIS(const int a[], int b[], const int n)
{
	int i;
	int high, low, mid;
	int res;

	if(n <= 0){
		return 0;
	}

	if(!a || !b){
		return -1;
	}

	res = 1;
	b[0] = a[0];
	for(i = 1; i < n; ++i){
		if(a[i] >= b[res - 1]){
			b[res++] = a[i];
		}else if(a[i] < b[0]){
			b[0] = a[i];
		}else{
			low = 0;
			high = res - 1;
			while(true){
				if(high - low <= 1){
					break;
				}

				mid = (low + high) / 2;
				if(a[i] < b[mid]){
					high = mid;
				}else{
					low = mid;
				}
			}
			b[high] = a[i];
		}
	}

	return res;
}

int main()
{
	int i;
	int ti;

	ti = 0;
	while(true){
		n = 0;
		memset(a, 0, 100000 * sizeof(int));
		while(scanf("%d", &a[n]) == 1){
			if(a[n] == -1){
				break;
			}else{
				++n;
			}
		}
		if(!n){
			break;
		}else{
			++ti;
		}

		memset(b, 0, 100000 * sizeof(int));
		for(i = 0; i < n - 1 - i; ++i){
			res = a[i];
			a[i] = a[n - 1 - i];
			a[n - 1 - i] = res;
		}

		res = LIS(a, b, n);

		if(ti > 1){
			printf("\n");
		}
		printf("Test #%d:\n", ti);
		printf("  maximum possible interceptions: %d\n", res);
	}

	return 0;
}

