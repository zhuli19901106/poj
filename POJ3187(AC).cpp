#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int t[12][12];
int n, s;
int b[12];
bool suc;
int c[12];
int cc;

void myswap(int &a, int &b)
{
	int t;

	t = a;
	a = b;
	b = t;
}

void dfs(int sum, int idx)
{
	int i;

	if(suc){
		return;
	}

	if(sum == s && cc == n){
		i = 0;
		while(i < cc - 1 - i){
			if(c[i] > c[cc - 1 - i]){
				myswap(c[i], c[cc - 1 - i]);
			}
			++i;
		}
		for(i = 0; i < cc; ++i){
			if(i == 0){
				printf("%d", c[i]);
			}else{
				printf(" %d", c[i]);
			}
		}
		printf("\n");
		suc = true;
	}

	if(idx > n){
		return;
	}

	for(i = 1; i <= n; ++i){
		if(!b[i]){
			b[i] = 1;
			c[cc++] = i;
			dfs(sum + i * t[n][idx], idx + 1);
			--cc;
			b[i] = 0;
			if(suc){
				return;
			}
		}
	}
}

int main()
{
	int i, j;

	memset(t, 0, 12 * 12 * sizeof(int));
	t[1][1] = 1;
	for(i = 2; i <= 11; ++i){
		for(j = 1; j <= i; ++j){
			if(j == 1){
				t[i][j] = t[i - 1][j];
			}else if(j == i){
				t[i][j] = t[i - 1][j - 1];
			}else{
				t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
			}
		}
	}

	while(scanf("%d%d", &n, &s) == 2){
		memset(b, 0, 12 * sizeof(int));
		memset(c, 0, 12 * sizeof(int));
		suc = false;
		cc = 0;
		dfs(0, 1);
	}

	return 0;
}
