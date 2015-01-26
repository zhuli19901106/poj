#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char a[10][1024][2049];
int main()
{
	int i, j, k;
	int n, w, h;

	memset(a, ' ', 10 * 1024 * 2049 * sizeof(char));
	a[0][0][1] = '/';
	a[0][0][2] = '\\';
	a[0][1][0] = '/';
	a[0][1][1] = '_';
	a[0][1][2] = '_';
	a[0][1][3] = '\\';

	for(i = 1; i < 10; ++i){
		w = 1 << (i + 1);
		h = 1 << i;
		for(j = 0; j < h; ++j){
			for(k = 0; k < w; ++k){
				a[i][j][h + k] = a[i - 1][j][k];
			}
		}
 		for(j = 0; j < h; ++j){
			for(k = 0; k < w; ++k){
				a[i][j + h][k] = a[i - 1][j][k];
			}
		}
		for(j = 0; j < h; ++j){
			for(k = 0; k < w; ++k){
				a[i][j + h][k + w] = a[i - 1][j][k];
			}
		}
	}

	for(i = 0; i < 10; ++i){
		w = 1 << (i + 2);
		h = 1 << (i + 1);
		for(j = 0; j < h; ++j){
			k = 2048;
			while(k >= 0 && a[i][j][k] == ' '){
				--k;
			}
			a[i][j][k + 1] = 0;
		}
	}
	
	while(scanf("%d", &n) == 1 && n){
		h = 1 << n;
		--n;
		for(i = 0; i < h; ++i){
			printf("%s\n", a[n][i]);
		}
		printf("\n");
	}

	return 0;
}
