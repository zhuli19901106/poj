#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int n;

	while(scanf("%d", &n) == 1 && n){
		if(n % 2){
			printf("%d\n", n - 1);
		}else{
			printf("No Solution!\n");
		}
	}

	return 0;
}
