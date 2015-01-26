#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a, b, c;
	int i, n;

	while(scanf("%d", &n) == 1){
		printf("Gnomes:\n");
		for(i = 0; i < n; ++i){
			scanf("%d%d%d", &a, &b, &c);
			if(a < b && b < c){
				printf("Ordered\n");
			}else if(a > b && b > c){
				printf("Ordered\n");
			}else{
				printf("Unordered\n");
			}
		}
	}

	return 0;
}
