#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, a, b;

int main()
{
	int i;
	int max_i;
	int max_a;

	while(scanf("%d", &n) == 1 && n){
		max_i = -1;
		max_a = -1;
		for(i = 0; i < n; ++i){
			scanf("%d%d", &a, &b);
			if(a + b > 8 && a + b > max_a){
				max_a = a + b;
				max_i = i;
			}
		}
		if(max_i == -1){
			printf("0\n");
		}else{
			printf("%d\n", max_i + 1);
		}
	}

	return 0;
}
