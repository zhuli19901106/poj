#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
	int a;
	int b;
	int d;
}st;

bool comparator(const st &x, const st &y)
{
	return x.d < y.d;
}

vector<st> v;
int n, m;
int slim, min_slim;
int dj[101];

int find_root(int x)
{
	int k, r;

	r = x;
	while(dj[r] != r){
		r = dj[r];
	}

	k = x;
	while(x != r){
		x = dj[x];
		dj[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int i, j, cc;
	int ra, rb;
	st vst;

	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		v.clear();
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &vst.a, &vst.b, &vst.d);
			v.push_back(vst);
		}
		sort(v.begin(), v.end(), comparator);

		min_slim = 1000000000;
		for(i = 0; i < m; ++i){
			for(j = 1; j <= n; ++j){
				dj[j] = j;
			}

			cc = 0;
			slim = 0;
			for(j = i; j < m; ++j){
				if(cc >= n - 1){
					break;
				}else{
					if(slim >= min_slim){
						break;
					}else{
						ra = find_root(v[j].a);
						rb = find_root(v[j].b);
						if(ra != rb){
							dj[ra] = rb;
							find_root(v[j].a);
							find_root(v[j].b);
							slim = v[j].d - v[i].d;
							++cc;
						}
					}
				}
			}

			if(cc == n - 1){
				if(slim < min_slim){
					min_slim = slim;
				}
			}
		}
		v.clear();

		if(min_slim == 1000000000){
			printf("-1\n");
		}else{
			printf("%d\n", min_slim);
		}
	}

	return 0;
}

