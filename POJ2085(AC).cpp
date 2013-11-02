#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;
int main()
{
	LL i, k;
	LL n, m;
	LL a[50001];
	
	while(scanf("%lld%lld", &n, &m) == 2 && (n != -1 || m != -1)){
		if(m > n * (n - 1) / 2){
			//invalid input
			continue;
		}
 		a[0] = 0;
		for(i = 1; i < n; ++i){
			a[i] = a[i - 1] + i;
		}
		for(k = 0; k <= n; ++k){
			if(m <= a[k]){
				break;
			}
		}
		for(i = 1; i < n - k; ++i){
			if(i == 1){
				printf("%d", i);
			}else{
				printf(" %d", i);
			}
		}
		if(k > 0){
			if(k < n - 1){
				printf(" %d", (n - k) + (m - a[k - 1]));
			}else{
				printf("%d", (n - k) + (m - a[k - 1]));
			}
		}
		for(i = n; i >= n - k; --i){
			if(k == 0 || i != (n - k) + (m - a[k - 1])){
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	
	return 0;
}

