#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char a[20][20];
int cc;

void solve(int x, int y)
{
	int i, j;
	int b[10];

	memset(b, 0, 10 * sizeof(int));
	for(i = 0; i < 9; ++i){
		++b[a[i][y] - '0'];
	}
	if(b[0] == 1){
		for(i = 1; i <= 9; ++i){
			if(b[i] == 0){
				a[x][y] = i + '0';
				break;
			}
		}

		return;
	}

	memset(b, 0, 10 * sizeof(int));
	for(i = 0; i < 9; ++i){
		++b[a[x][i] - '0'];
	}
	if(b[0] == 1){
		for(i = 1; i <= 9; ++i){
			if(b[i] == 0){
				a[x][y] = i + '0';
				break;
			}
		}

		return;
	}

	memset(b, 0, 10 * sizeof(int));
	for(i = 0; i < 3; ++i){
		for(j = 0; j < 3; ++j){
			++b[a[x / 3 * 3 + i][y / 3 * 3 + j] - '0'];
		}
	}
	if(b[0] == 1){
		for(i = 1; i <= 9; ++i){
			if(b[i] == 0){
				a[x][y] = i + '0';
				break;
			}
		}

		return;
	}
}

int main()
{
	int i, j;
	int t, ti;

	scanf("%d", &t);
	for(ti = 1; ti <= t; ++ti){
		for(i = 0; i < 9; ++i){
			scanf("%s", a[i]);
		}

		cc = 0;
		for(i = 0; i < 9; ++i){
			for(j = 0; j < 9; ++j){
				if(a[i][j] == '0'){
					++cc;
				}
			}
		}

		while(cc > 0){
			for(i = 0; i < 9; ++i){
				for(j = 0; j < 9; ++j){
					if(a[i][j] == '0'){
						solve(i, j);
						if(a[i][j] != '0'){
							--cc;
						}
					}
				}
			}
		}

		printf("Scenario #%d:\n", ti);
		for(i = 0; i < 9; ++i){
			printf("%s\n", a[i]);
		}
		printf("\n");
	}
	
	return 0;
}

