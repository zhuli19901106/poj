#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[4] = {25, 10, 5, 1};
int b[4];
int c[4];
bool suc;
int minc;

void dfs(int n, int index)
{
	int i, j;
	int tmp;

	if(suc){
		return;
	}

	if(n == 0 && minc == c[0] + c[1] + c[2] + c[3]){
		printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n", c[0], c[1], c[2], c[3]);
		suc = true;
		return;
	}

	for(i = index; i < 4; ++i){
		tmp = n / a[i];
		if(tmp > b[i]){
			tmp = b[i];
		}
		for(j = tmp; j >= 0; --j){
			c[i] += j;
			b[i] -= j;
			dfs(n - a[i] * j, i + 1);
			b[i] += j;
			c[i] -= j;
		}
	}
}

void dfs2(int n, int index)
{
	int i, j;
	int tmp;

	if(n == 0){
		if(minc > c[0] + c[1] + c[2] + c[3]){
			minc = c[0] + c[1] + c[2] + c[3];
		}
		suc = true;
		return;
	}

	for(i = index; i < 4; ++i){
		tmp = n / a[i];
		if(tmp > b[i]){
			tmp = b[i];
		}
		for(j = tmp; j >= 0; --j){
			c[i] += j;
			b[i] -= j;
			dfs2(n - a[i] * j, i + 1);
			b[i] += j;
			c[i] -= j;
		}
	}
}

int main()
{
	int n;

	while(scanf("%d%d%d%d%d", &b[0], &b[1], &b[2], &b[3], &n) == 5){
		if(!(b[0] || b[1] || b[2] || b[3] || n)){
			break;
		}
		suc = false;
		memset(c, 0, 4 * sizeof(int));
		minc = 9999999;
		dfs2(n, 0);
		if(!suc){
			printf("Cannot dispense the desired amount.\n");
			continue;
		}
		suc = false;
		memset(c, 0, 4 * sizeof(int));
		dfs(n, 0);
	}
	
	return 0;
}
