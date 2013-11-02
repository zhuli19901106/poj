#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[7][7];
int n;
int minres;

int calc()
{
	int res, sum, i, j;

	res = -99999999;
	for(j = 0; j < n; ++j){
		sum = 0;
		for(i = 0; i <n; ++i){
			sum += a[i][j];
		}
		if(sum > res){
			res = sum;
		}
	}

	return res;
}

void dfs(int row)
{
	int i, j;
	int tmp;

	if(row >= n){
		tmp = calc();
		if(tmp < minres){
			minres = tmp;
		}

		return;
	}

	for(i = 0; i < n; ++i){
		dfs(row + 1);
		tmp = a[row][0];
		for(j = 0; j < n - 1; ++j){
			a[row][j] = a[row][j + 1];
		}
		a[row][n - 1] = tmp;
	}
}

int main()
{
	int i, j;

	while(scanf("%d", &n) == 1 && n != -1){
		memset(a, 0, 7 * 7 * sizeof(int));
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		minres = 99999999;
		dfs(1);
		printf("%d\n", minres);
	}

	return 0;
}

