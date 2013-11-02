#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int& mymin(const int &a, const int &b)
{
	return a < b ? a : b;
}

const int INF = 2000000000;
int a[100];
int n, s, res;

void dfs(int index, int sum)
{
	int i;

	if(sum >= s){
		if(sum < res){
			res = sum;
		}
		return;
	}

	if(index >= n){
		return;
	}

	for(i = index; i < n; ++i){
		dfs(i + 1, sum + a[i]);
	}
}

int main()
{
	int i;

	while(scanf("%d%d", &n, &s) == 2){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		res = INF;
		dfs(0, 0);
		printf("%d\n", res - s);
	}

	return 0;
}

