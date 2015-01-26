#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int d[62];
int dc;
int a[181];

void dfs(int dart_count, int dart_index, int score)
{
	int i;
	
	if(score > 0){
		++a[score];
	}
	
	if(dart_count >= 3){
		return;
	}
	for(i = dart_index; i < dc; ++i){
		dfs(dart_count + 1, i, score + d[i]);
	}
}

int main()
{
	int i;
	int t, ti;
	int n;
	
	dc = 0;
	for(i = 1; i <= 20; ++i){
		d[dc++] = i;
		d[dc++] = i * 2;
		d[dc++] = i * 3;
	}
	d[dc++] = 25;
	d[dc++] = 50;
	sort(d, d + dc);
	memset(a, 0, 181 * sizeof(int));
	
	dfs(0, 0, 0);
	
	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%d", &n);
			printf("Scenario #%d:\n", ti);
			printf("%d\n\n", a[n]);
		}
	}
	
	return 0;
}
