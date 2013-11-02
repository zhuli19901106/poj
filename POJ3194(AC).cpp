#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
const int MAXN = 105;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int cc;

void search(int r, int c, int idx)
{
	if(!b[r - 1][c] && a[r - 1][c] == idx){
		b[r - 1][c] = 1;
		--cc;
		search(r - 1, c, idx);
	}
	if(!b[r + 1][c] && a[r + 1][c] == idx){
		b[r + 1][c] = 1;
		--cc;
		search(r + 1, c, idx);
	}
	if(!b[r][c - 1] && a[r][c - 1] == idx){
		b[r][c - 1] = 1;
		--cc;
		search(r, c - 1, idx);
	}
	if(!b[r][c + 1] && a[r][c + 1] == idx){
		b[r][c + 1] = 1;
		--cc;
		search(r, c + 1, idx);
	}
}

int main()
{
	int i, j;
	int r, c;

	while(scanf("%d", &n) == 1 && n){
		memset(a, 0, MAXN * MAXN * sizeof(int));
		memset(b, 0, MAXN * MAXN * sizeof(int));
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				a[i][j] = n;
			}
		}
		for(i = 1; i <= n - 1; ++i){
			for(j = 1; j <= n; ++j){
				scanf("%d%d", &r, &c);
				a[r][c] = i;
			}
		}

		cc = n * n;
		for(i = 1; i <= n; ++i){
			for(r = 1; r <= n; ++r){
				for(c = 1; c <= n; ++c){
					if(a[r][c] == i){
						break;
					}
				}
				if(a[r][c] == i){
					break;
				}
			}
			b[r][c] = 1;
			--cc;
			search(r, c, i);

			if(cc != (n - i) * n){
				break;
			}
		}

		if(i > n){
			printf("good\n");
		}else{
			printf("wrong\n");
		}
	}

	return 0;
}

