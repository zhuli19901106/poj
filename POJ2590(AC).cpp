#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i;
	int x;
	int y;
	int n;
	int k;
	int t;
	
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d%d", &x, &y);
		n = y - x;
		if(n < 0){
			n = -n;
		}else if(n == 0){
			printf("0\n");
			continue;
		}
		
		k = (int)sqrt(1.0 * n);
		if(n == k * k){
			printf("%d\n", 2 * k - 1);
		}else if(n > k * k && n <= k * k + k){
			printf("%d\n", 2 * k);
		}else{
			printf("%d\n", 2 * k + 1);
		}
	}
	
	return 0;
}

