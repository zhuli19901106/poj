#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[355][355];
int b[355][355];
int n;
int res;

int main()
{
	int i, j;

	while(scanf("%d", &n) == 1){
		memset(a, 0, 355 * 355 * sizeof(int));
		memset(b, 0, 355 * 355 * sizeof(int));
		for(i = 0; i < n; ++i){
			for(j = 0; j <= i; ++j){
				scanf("%d", &a[i][j]);
			}
		}

		b[0][0] = a[0][0];
		for(i = 1; i < n; ++i){
			for(j = 0; j <= i; ++j){
				if(j == 0){
					b[i][j] = b[i - 1][j] + a[i][j];
				}else if(j == i){
					b[i][j] = b[i - 1][j - 1] + a[i][j];
				}else{
					if(b[i - 1][j - 1] > b[i - 1][j]){
						b[i][j] = b[i - 1][j - 1] + a[i][j];
					}else{
						b[i][j] = b[i - 1][j] + a[i][j];
					}
				}
			}
		}

		res = -1;
		for(i = 0; i < n; ++i){
			if(b[n - 1][i] > res){
				res = b[n - 1][i];
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
