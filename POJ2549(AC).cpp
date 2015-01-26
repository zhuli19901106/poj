#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;
LL a[1005], sum;
int n;

bool bsearch(int left, int right, LL key, int i, int j)
{
	int mid;

	while(left <= right){
		mid = (left + right) / 2;
		if(a[mid] == key && mid != i && mid != j){
			return true;
		}else if(a[mid] < key){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}

	return false;
}

int main()
{
	int i, j, k;
	bool found;
	
	while(scanf("%d", &n) == 1 && n){
		for(i = 0; i < n; ++i){
			scanf("%lld", &a[i]);
		}
		sort(a, a + n);
		if(n < 4){
			printf("no solution\n");
			continue;
		}

		found = false;
		for(i = n - 1; i >= 0; --i){
			sum = a[i];
			for(j = n - 1; j >= 0; --j){
				if(i == j){
					continue;
				}
				if(a[j] + a[0] + a[1] > sum){
					continue;
				}
				for(k = n - 1; k >= 0; --k){
					if(k == i || k == j){
						continue;
					}
					if(bsearch(0, k - 1, sum - a[j] - a[k], i, j)){
						found = true;
					}
					if(found){
						break;
					}
				}
				if(found){
					break;
				}
			}
			if(found){
				break;
			}
		}
		
		if(!found){
			printf("no solution\n");
		}else{
			printf("%lld\n", sum);
		}
	}
	
	return 0;
}
