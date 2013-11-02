#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int dj[1005];
typedef struct edge{
	int x;
	int y;
	int len;
}Edge;
Edge e[15005];
int idx[1100];
int idc;
int n, m;

int comp(const void *a, const void *b)
{
	const Edge *ea, *eb;
	
	ea = (const Edge *)a;
	eb = (const Edge *)b;
	
	return ea->len - eb->len;
}

int find_compress(int dj[], int x)
{
	if(dj[x] != dj[dj[x]]){
		dj[x] = find_compress(dj, dj[x]);
	}
	
	return dj[x];
}

int main()
{
	int rx, ry;
	int max_len;
	int i;
	
	while(true){
		if(scanf("%d%d", &n, &m) != 2){
			break;
		}
		
		for(i = 1; i <= n; ++i){
			dj[i] = i;
		}
		
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].len);
		}
		qsort(e, m, sizeof(Edge), comp);
		
		idc = 0;
		for(i = 0; i < m; ++i){
			if(idc == n - 1){
				break;
			}
			rx = find_compress(dj, e[i].x);
			ry = find_compress(dj, e[i].y);
			if(rx == ry){
				//they're already connected.
				continue;
			}else{
				dj[rx] = ry;
				find_compress(dj, e[i].x);
				idx[idc] = i;
				++idc;
			}
		}
		max_len = e[idx[idc - 1]].len;
		printf("%d\n", max_len);
		printf("%d\n", idc);
		for(i = 0; i < idc; ++i){
			printf("%d %d\n", e[idx[i]].x, e[idx[i]].y);
		}
	}
	
	return 0;
}

