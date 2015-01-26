#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef struct st{
	int a;
	int b;
	int c;
}st;

bool comparator(const st &x, const st &y)
{
	return x.c < y.c;
}

const int MAXP = 55;
int p, r;
int f[MAXP][MAXP];
int dj[MAXP];
int res;
vector<st> v;

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
	int ra, rb;
	st vst;
	int i, cc;

	while(scanf("%d", &p) == 1 && p){
		scanf("%d", &r);
		v.clear();
		memset(dj, 0, MAXP * sizeof(int));
		memset(f, 0, MAXP * MAXP * sizeof(int));
		for(i = 0; i < r; ++i){
			scanf("%d%d%d", &vst.a, &vst.b, &vst.c);
			v.push_back(vst);
		}
		sort(v.begin(), v.end(), comparator);
		for(i = 0; i < p; ++i){
			dj[i] = i;
		}
		res = 0;
		cc = 0;
		for(i = 0; i < (int)v.size(); ++i){
			if(cc >= p - 1){
				break;
			}else{
				ra = find_root(v[i].a);
				rb = find_root(v[i].b);
				if(ra != rb){
					dj[ra] = rb;
					find_root(v[i].a);
					find_root(v[i].b);
					res += v[i].c;
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
