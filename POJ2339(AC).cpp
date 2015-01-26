#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b0, b1;
char a[2][105][105];
int d[4][2] = {{-1,  0}, {+1,  0}, { 0, -1}, { 0, +1}};
int r, c, n;

int main()
{
	char s[1000];
	int t, ti;
	int i, j, k, di;
	int x, y;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			if(ti > 0){
				printf("\n");
			}
			scanf("%d%d%d", &r, &c, &n);

			b0 = 0;
			b1 = 1;
			for(i = 0; i < r; ++i){
				scanf("%s", s);
				for(j = 0; j < c; ++j){
					a[b0][i][j] = s[j];
				}
			}

			for(k = 0; k < n; ++k){
				for(i = 0; i < r; ++i){
					for(j = 0; j < c; ++j){
						a[b1][i][j] = 0;
					}
				}
				for(i = 0; i < r; ++i){
					for(j = 0; j < c; ++j){
						for(di = 0; di < 4; ++di){
							x = i + d[di][0];
							y = j + d[di][1];
							if(x >= 0 && x <= r - 1 && y >= 0 && y <= c - 1){
								if(a[b0][i][j] == 'R' && a[b0][x][y] == 'S'){
									a[b1][x][y] = 'R';
								}else if(a[b0][i][j] == 'S' && a[b0][x][y] == 'P'){
									a[b1][x][y] = 'S';
								}else if(a[b0][i][j] == 'P' && a[b0][x][y] == 'R'){
									a[b1][x][y] = 'P';
								}
							}
						}
					}
				}

				for(i = 0; i < r; ++i){
					for(j = 0; j < c; ++j){
						if(!a[b1][i][j]){
							a[b1][i][j] = a[b0][i][j];
						}
					}
				}

				for(i = 0; i < r; ++i){
					for(j = 0; j < c; ++j){
						a[b0][i][j] = a[b1][i][j];
					}
				}
			}

			for(i = 0; i < r; ++i){
				for(j = 0; j < c; ++j){
					printf("%c", a[b0][i][j]);
				}
				printf("\n");
			}
		}
	}
	
	return 0;
}
