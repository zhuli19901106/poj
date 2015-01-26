#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[105];
int n, d;

int main()
{
	int i, j;
	int tmp;

	while(scanf("%d%d", &n, &d) == 2 && (n || d)){
		for(i = 0; i < n; ++i){
			a[i] = 1;
		}
		for(i = 0; i < d; ++i){
			for(j = 0; j < n; ++j){
				scanf("%d", &tmp);
				a[j] &= tmp;
			}
		}

		tmp = 0;
		for(i = 0; i < n; ++i){
			tmp |= a[i];
		}

		if(tmp){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}
