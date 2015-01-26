#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[30][30];
int n, s;

int main()
{
	int i, j;

	while(scanf("%d%d", &n, &s) == 2){
		for(i = 0; i < n; ++i){
			for(j = 0; j <= i; ++j){
				a[j][i] = s;
				if(s == 9){
					s = 1;
				}else{
					++s;
				}
			}
		}

		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				if(j <  i){
					printf(" ");
				}else{
					printf("%1d", a[i][j]);
				}
				if(j < n - 1){
					printf(" ");
				}else{
					printf("\n");
				}
			}
		}
	}

	return 0;
}
