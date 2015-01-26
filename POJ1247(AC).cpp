#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a[50];
	int n;
	int i;
	int sum;
	int par;
	bool suc;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		if(n == 0){
			break;
		}

		sum = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &a[i]);
			sum = sum + a[i];
		}
		
		suc = false;
		par = 0;
		if(sum % 2 == 1){
			printf("No equal partitioning.\n");
			continue;
		}
		for(i = 0; i < n; i++){
			par = par + a[i];
			if(par == sum / 2){
				suc = true;
				break;
			}else if(par > sum / 2){
				break;
			}
		}
		
		if(suc){
			printf("Sam stops at position %d and Ella stops at position %d.\n", i + 1, (i + 1) % n + 1);
		}else{
			printf("No equal partitioning.\n");
		}
	}
	
	return 0;
}
