#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int r, c, maxlen;
int h[105][105];
int len[105][105];
int d[4][2] = {
	{-1,  0},
	{+1,  0},
	{ 0, -1},
	{ 0, +1}
};
const int INF = 99999;
typedef struct st{
	int i;
	int j;
	int h;
}st;
st v[10005];

int comparator(const void *a, const void *b)
{
	const st *sa, *sb;

	sa = (const st *)a;
	sb = (const st *)b;
	if(sa->h > sb->h){
		return 1;
	}else{
		return -1;
	}
}

int main()
{
	int i, j, k;
	
	while(true){
		if(scanf("%d%d", &r, &c) != 2){
			break;
		}
		
		for(i = 0; i <= r + 1; ++i){
			for(j = 0; j <= c + 1; ++j){
				h[i][j] = INF;
			}
		}
		
		k = 0;
		for(i = 1; i <= r; ++i){
			for(j = 1; j <= c; ++j){
				scanf("%d", &h[i][j]);
				v[k].i = i;
				v[k].j = j;
				v[k].h = h[i][j];
				++k;
				len[i][j] = 0;
			}
		}
		qsort(v, r * c, sizeof(st), comparator);
		
		for(i = 0; i < r * c; ++i){
			for(k = 0; k < 4; ++k){
				if(
					h[v[i].i][v[i].j] < h[v[i].i + d[k][0]][v[i].j + d[k][1]]
					&& len[v[i].i][v[i].j] >= len[v[i].i + d[k][0]][v[i].j + d[k][1]]
				){
					len[v[i].i + d[k][0]][v[i].j + d[k][1]] = len[v[i].i][v[i].j] + 1;
				}
			}
		}

		maxlen = 0;
		for(i = 0; i < r * c; ++i){
			if(len[v[i].i][v[i].j] > maxlen){
				maxlen = len[v[i].i][v[i].j];
			}
		}

		printf("%d\n", maxlen + 1);
	}
	
	return 0;
}

