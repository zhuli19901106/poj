#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char a[4][5];
int n;
int maxc;

void dfs(int index, int c)
{
	int i, j, k;

	if(c > maxc){
		maxc = c;
	}

	if(index >= n * n){
		return;
	}

	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			if(i * n + j < index){
				continue;
			}else if(a[i][j] == '.'){
				k = i - 1;
				while(true){
					if(k < 0){
						break;
					}else if(a[k][j] == 'X'){
						break;
					}else if(a[k][j] == 'R'){
						k = -2;
						break;
					}else{
						--k;
					}
				}
				if(k == -2){
					continue;
				}

				k = i + 1;
				while(true){
					if(k > n - 1){
						break;
					}else if(a[k][j] == 'X'){
						break;
					}else if(a[k][j] == 'R'){
						k = -2;
						break;
					}else{
						++k;
					}
				}
				if(k == -2){
					continue;
				}

				k = j - 1;
				while(true){
					if(k < 0){
						break;
					}else if(a[i][k] == 'X'){
						break;
					}else if(a[i][k] == 'R'){
						k = -2;
						break;
					}else{
						--k;
					}
				}
				if(k == -2){
					continue;
				}

				k = j + 1;
				while(true){
					if(k > n - 1){
						break;
					}else if(a[i][k] == 'X'){
						break;
					}else if(a[i][k] == 'R'){
						k = -2;
						break;
					}else{
						++k;
					}
				}
				if(k == -2){
					continue;
				}
				
				a[i][j] = 'R';
				dfs(i * n + j + 1, c + 1);
				a[i][j] = '.';
			}else{
				continue;
			}
		}
	}
}

int main()
{
	int i;

	while(scanf("%d", &n) == 1 && n){
		for(i = 0; i < n; ++i){
			scanf("%s", a[i]);
		}
		maxc = 0;
		dfs(0, 0);

		printf("%d\n", maxc);
	}

	return 0;
}
