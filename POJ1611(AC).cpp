#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[30001];
int k;
int n, m;

int find_compress(int dj[], int x)
{
	int r;
	int k;

	r = x;
	while(r != dj[r]){
		r = dj[r];
	}

	while(x != r){
		k = dj[x];
		dj[x] = r;
		x = k;
	}

	return r;
}

int main()
{
	int tmp;
	int i, j;
	int rx, ry;
	int count, srt;
	
	while(true){
		if(scanf("%d%d", &n, &m) != 2){
			break;
		}else if(0 == n && 0 == m){
			break;
		}
		
		for(i = 0; i < n; ++i){
			a[i] = i;
		}
		
		for(i = 0; i < m; ++i){
			scanf("%d", &k);
			for(j = 0; j < k; ++j){
				scanf("%d", &tmp);
				if(j == 0){
					rx = find_compress(a, tmp);
				}else{
					rx = find_compress(a, rx);
					ry = find_compress(a, tmp);
					if(rx != ry){
						a[ry] = rx;
						find_compress(a, tmp);
					}
				}
			}
		}
		
		srt = find_compress(a, 0);
		count = 1;
		for(i = 1; i < n; ++i){
			if(find_compress(a, i) == srt){
				++count;
			}
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}

