#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[101][101];

void color_square(int x, int y, int ll, int val)
{
	int i, j;

	for(i = x; i < x + ll; ++i){
		for(j = y; j < y + ll; ++j){
			a[i][j] = val;
		}
	}
}

int main()
{
	char s[10];
	int ti, t;
	int x, y, ll, res;
	int i, j;
	
	while(scanf("%d", &t) == 1){
		memset(a, 0, 101 * 101 * sizeof(int));
		for(ti = 0; ti < t; ++ti){
			scanf("%s%d%d%d", s, &x, &y, &ll);
			if(strcmp(s, "WHITE") == 0){
				color_square(x, y, ll, 0);
			}else if(strcmp(s, "BLACK") == 0){
				color_square(x, y, ll, 1);
			}else if(strcmp(s, "TEST") == 0){
				res = 0;
				for(i = x; i < x + ll; ++i){
					for(j = y; j < y + ll; ++j){
						if(a[i][j]){
							++res;
						}
					}
				}
				printf("%d\n", res);
			}
		}
	}

	return 0;
}

