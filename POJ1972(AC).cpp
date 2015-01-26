#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int find_max(int a[], int n, int x, int y)
{
	int i;
	int res;

	res = -1;
	for(i = 1; i <= n; ++i){
		if(a[i] == x || a[i] == y){
			continue;
		}else if(a[i] > res){
			res = a[i];
		}
	}

	return res;
}

int n;
int a[10001][7];
int b[10001][7];
int res[7];
int maxres;
const int op[7] = {0, 6, 4, 5, 2, 3, 1};

int main()
{
	int tt, bb;
	int i, j;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			for(i = 1; i <= n; ++i){
				for(j = 1; j <= 6; ++j){
					scanf("%d", &a[i][j]);
					b[i][a[i][j]] = j;
				}
			}
			for(i = 1; i <= 6; ++i){
				tt = a[1][i];
				bb = a[1][op[b[1][a[1][i]]]];
				res[i] = find_max(a[1], 6, tt, bb);
				for(j = 2; j <= n; ++j){
					tt = bb;
					bb = a[j][op[b[j][tt]]];
					res[i] += find_max(a[j], 6, tt, bb);
				}
			}
			maxres = res[1];
			for(i = 2; i <= 6; ++i){
				if(res[i] > maxres){
					maxres = res[i];
				}
			}

			printf("%d\n", maxres);
		}
	}

	return 0;
}
