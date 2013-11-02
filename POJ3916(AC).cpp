#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int l;
	int a;
	int n;

	while(scanf("%d", &n) == 1 && n){
		l = -1;
		while(n--){
			scanf("%d", &a);
			if(l != a){
				printf("%d ", a);
				l = a;
			}
		}
		printf("$\n");
	}

	return 0;
}

