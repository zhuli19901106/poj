#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[26][26];
int c[26];
int n;

void dfs(int x)
{
	int i;
	int tag[27];

	if(c[x] > 0){
		//This node is already colored.
		return;
	}

	memset(tag, 0, 27 * sizeof(int));
	for(i = 0; i < n; ++i){
		if(a[x][i] && c[i] > 0){
			tag[c[i]] = 1;
		}
	}

	for(i = 1; i <= 26; ++i){
		if(!tag[i]){
			c[x] = i;
			break;
		}
	}

	for(i = 0; i < n; ++i){
		if(a[x][i] || !c[i]){
			dfs(i);
		}
	}
}

int main()
{
	int i, j;
	int x, y;
	char str[100];

	while(scanf("%d", &n) == 1 && n > 0){
		memset(a, 0, 26 * 26 * sizeof(int));
		memset(c, 0, 26 * sizeof(int));
		for(i = 0; i < n; ++i){
			scanf("%s", str);
			x = str[0] - 'A';
			for(j = 2; str[j]; ++j){
				y = str[j] - 'A';
				a[x][y] = a[y][x] = 1;
			}
		}
		dfs(0);
		j = c[0];
		for(i = 1; i < n; ++i){
			if(c[i] > j){
				j = c[i];
			}
		}
		if(j == 1){
			printf("%d channel needed.\n", j);
		}else{
			printf("%d channels needed.\n", j);
		}
	}

	return 0;
}

