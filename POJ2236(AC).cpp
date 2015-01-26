#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int dj[MAXN];
int f[MAXN][MAXN];
int b[MAXN];
int n;
double x[MAXN], y[MAXN], d;

int find_root(int x)
{
	int r, k;

	r = x;
	while(r != dj[r]){
		r = dj[r];
	}

	k = x;
	while(x != r){
		x = dj[k];
		dj[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int i, j;
	char s[10];
	int p, q, rp, rq;

	scanf("%d%lf", &n, &d);
	for(i = 1; i <= n; ++i){
		scanf("%lf%lf", &x[i], &y[i]);
	}

	memset(dj, 0, MAXN * sizeof(int));
	for(i = 1; i <= n; ++i){
		dj[i] = i;
	}

	memset(f, 0, MAXN * MAXN * sizeof(int));
	for(i = 1; i <= n; ++i){
		for(j = i + 1; j <= n; ++j){
			if((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= d * d){
				f[i][j] = f[j][i] = 1;
			}
		}
	}

	memset(b, 0, MAXN * sizeof(int));
	while(scanf("%s", s) == 1){
		if(s[0] == 'S'){
			//Testing the connectivity between two nodes
			scanf("%d%d", &p, &q);
			if(b[p] && b[q]){
				rp = find_root(p);
				rq = find_root(q);
				if(rp == rq){
					printf("SUCCESS\n");
				}else{
					printf("FAIL\n");
				}
			}else{
				printf("FAIL\n");
			}
		}else if(s[0] == 'O'){
			//Repairing a node
			scanf("%d", &p);
			if(!b[p]){
				b[p] = 1;
				for(q = 1; q <= n; ++q){
					if(q == p){
						continue;
					}
					if(f[p][q] && b[q]){
						rp = find_root(p);
						rq = find_root(q);
						if(rp != rq){
							dj[rq] = rp;
						}
						find_root(p);
						find_root(q);
					}
				}
			}
		}else{
			//Invalid command
		}
	}

	return 0;
}
