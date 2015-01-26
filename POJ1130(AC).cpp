#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 105;
const int INF = 1000000;
int a0[MAXN][MAXN];
int b[MAXN];
int dist[MAXN];
int n, et, ans;

int dfs(int p)
{
	int i;

	if(p == et){
		return 1;
	}
	b[p] = 1;

	for(i = 0; i < n; ++i){
		if(!b[i] && a0[p][i]){
			if(dfs(i)){
				return 1;
			}
		}
	}

	return 0;
}

int main()
{
	int i;
	int x, y;
	queue<int> q;

	scanf("%d%d", &n, &et);
	memset(a0, 0, MAXN * MAXN * sizeof(int));
	while(scanf("%d%d", &x, &y) == 2){
		a0[x][y] = 1;
	}

	for(i = 0; i < n; ++i){
		dist[i] = INF;
	}
	q.push(et);
	dist[et] = 0;
	while(!q.empty()){
		y = q.front();
		q.pop();
		for(x = 0; x < n; ++x){
			if(a0[x][y] && dist[y] + 1 < dist[x]){
				q.push(x);
				dist[x] = dist[y] + 1;
			}
		}
	}

	ans = 0;
	for(i = 1; i < n; ++i){
		if(i == et){
			continue;
		}

		memset(b, 0, MAXN * sizeof(int));
		b[i] = 1;
		if(!dfs(0) && dist[i] < dist[ans]){
			ans = i;
		}
	}

	printf("Put guards in room %d.\n", ans);

	return 0;
}
