#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 105;
int b[MAXN];
int a[MAXN][MAXN];
int n;
int res;

int main()
{
	int i, j;

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			b[i] = 0;
		}
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		for(i = 0; i < n; ++i){
			for(j = i + 1; j < n; ++j){
				if(a[i][j] == 3){
					++b[i];
				}else if(a[j][i] == 3){
					++b[j];
				}
			}
		}
		j = i;
		for(i = 1; i < n; ++i){
			if(b[i] > b[j]){
				j = i;
			}
		}
		printf("%d\n", j + 1);
	}

	return 0;
}

