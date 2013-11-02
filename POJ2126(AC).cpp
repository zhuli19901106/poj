#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a, b, c;
	int n;
	int i;

	while(scanf("%d", &n) == 1){
		if(n <= 1){
			for(i = 0; i <= n; ++i){
				scanf("%d", &a);
			}
			printf("YES\n");
		}else if(n == 2){
			scanf("%d%d%d", &a, &b, &c);
			if(b * b >= 4 * a * c){
				printf("NO\n");
			}else{
				printf("YES\n");
			}
		}else{
			for(i = 0; i <= n; ++i){
				scanf("%d", &a);
			}
			printf("NO\n");
		}
	}

	return 0;
}

