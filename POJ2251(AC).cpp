#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int p1[3], p2[3];
int l, r, c;
char a[32][32][32];
int b[32][32][32];

typedef struct point{
	int x;
	int y;
	int z;
}Point;
queue<Point> q;
int d[6][3] = {
	{-1, 0, 0}, {+1, 0, 0},
	{0, -1, 0}, {0, +1, 0},
	{0, 0, -1}, {0, 0, +1}
};

int main()
{
	int i, j, k;
	char s[100];
	Point p, np;

	while(scanf("%d%d%d", &l, &r, &c) == 3 && (l || r || c)){
		for(i = 0; i <= l + 1; ++i){
			for(j = 0; j <= r + 1; ++j){
				for(k = 0; k <= c + 1; ++k){
					a[i][j][k] = '#';
				}
			}
		}

		for(i = 1; i <= l; ++i){
			for(j = 1; j <= r; ++j){
				scanf("%s", s);
				for(k = 1; k <= c; ++k){
					if(s[k - 1] == 'S'){
						p1[0] = i;
						p1[1] = j;
						p1[2] = k;
						a[i][j][k] = '.';
					}else if(s[k - 1] == 'E'){
						p2[0] = i;
						p2[1] = j;
						p2[2] = k;
						a[i][j][k] = '.';
					}else{
						a[i][j][k] = s[k - 1];
					}
				}
			}
		}

		for(i = 1; i <= l; ++i){
			for(j = 1; j <= r; ++j){
				for(k = 1; k <= c; ++k){
					b[i][j][k] = -1;
				}
			}
		}

		p.x = p1[0];
		p.y = p1[1];
		p.z = p1[2];
		b[p1[0]][p1[1]][p1[2]] = 0;
		q.push(p);
		while(!q.empty()){
			if(b[p2[0]][p2[1]][p2[2]] != -1){
				break;
			}
			p = q.front();
			q.pop();
			for(i = 0; i < 6; ++i){
				if(
					a[p.x + d[i][0]][p.y + d[i][1]][p.z + d[i][2]] == '.' && 
					b[p.x + d[i][0]][p.y + d[i][1]][p.z + d[i][2]] == -1
				){
					b[p.x + d[i][0]][p.y + d[i][1]][p.z + d[i][2]] = b[p.x][p.y][p.z] + 1;
					np.x = p.x + d[i][0];
					np.y = p.y + d[i][1];
					np.z = p.z + d[i][2];
					q.push(np);
				}
			}
		}
		while(!q.empty()){
			q.pop();
		}

		if(b[p2[0]][p2[1]][p2[2]] != -1){
			printf("Escaped in %d minute(s).\n", b[p2[0]][p2[1]][p2[2]]);
		}else{
			printf("Trapped!\n");
		}
	}

	return 0;
}
