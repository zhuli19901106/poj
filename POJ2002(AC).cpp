#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXLEN = 4005;
char a[MAXLEN][MAXLEN];
int res;
int ax[1005];
int ay[1005];

int main()
{
	int i, j;
	int n;
	int x, y;
	int x1, y1;
	int x2, y2;
	int dx, dy;
	int offset;
	
	offset = (MAXLEN - 1) / 2;
	while(scanf("%d", &n) == 1 && n != 0){
		memset(a, 0, MAXLEN * MAXLEN * sizeof(char));

		for(i = 0; i < n; ++i){
			scanf("%d%d", &x, &y);
			a[x + offset][y + offset] = 1;
			ax[i] = x + offset;
			ay[i] = y + offset;
			//offset by MAXLEN to avoid negative subscript of array.
		}
		res = 0;
		for(i = 0; i < n; ++i){
			for(j = 0; j < i; ++j){
				if(i == j){
					continue;
				}
				dx = ax[j] - ax[i];
				dy = ay[j] - ay[i];
				
				x1 = ax[j] + dy;
				y1 = ay[j] - dx;
				x2 = x1 - dx;
				y2 = y1 - dy;
				if(
					x1 >= 0 && x1 < MAXLEN
					&&
					y1 >= 0 && y1 < MAXLEN
					&&
					x2 >= 0 && x2 < MAXLEN
					&&
					y2 >= 0 && y2 < MAXLEN
				){
					if(a[x1][y1] && a[x2][y2]){
						++res;
					}
				}

				x1 = ax[j] - dy;
				y1 = ay[j] + dx;
				x2 = x1 - dx;
				y2 = y1 - dy;
				if(
					x1 >= 0 && x1 < MAXLEN
					&&
					y1 >= 0 && y1 < MAXLEN
					&&
					x2 >= 0 && x2 < MAXLEN
					&&
					y2 >= 0 && y2 < MAXLEN
				){
					if(a[x1][y1] && a[x2][y2]){
						++res;
					}
				}
			}
		}
		res = res / 4;
		printf("%d\n", res);
	}
	
	return 0;
}
