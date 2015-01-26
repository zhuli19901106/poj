#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 505;
int a[MAXN];
typedef struct st{
	int a;
	int b;
	int e;
}st;
vector<st> v;
int n;

bool comparator(const st &a, const st &b)
{
	if(a.e == b.e){
		if(a.a == b.a){
			return a.b < b.b;
		}else{
			return a.a < b.a;
		}
	}else{
		return a.e < b.e;
	}
}

int find_root(int x)
{
	int k, r;

	r = x;
	while(a[r] != r){
		r = a[r];
	}

	while(x != r){
		k = a[x];
		a[x] = r;
		x = k;
	}

	return r;
}

int main()
{
	int i, j;
	int t, ti;
	int tmp;
	st est;
	int ra, rb;
	int res;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			v.clear();
			for(i = 0; i < n; ++i){
				for(j = 0; j < n; ++j){
					scanf("%d", &tmp);
					if(tmp >= 1){
						est.a = i;
						est.b = j;
						est.e = tmp;
						v.push_back(est);
					}
				}
			}
			sort(v.begin(), v.end(), comparator);
			memset(a, 0, MAXN * sizeof(int));
			for(i = 0; i < n; ++i){
				a[i] = i;
			}

			j = 0;
			res = 0;
			for(i = 0; i < (int)v.size(); ++i){
				ra = find_root(v[i].a);
				rb = find_root(v[i].b);
				if(ra != rb){
					a[ra] = rb;
					find_root(v[i].a);
					find_root(v[i].b);
					++j;
				}
				if(v[i].e > res){
					res = v[i].e;
				}
				if(j >= n - 1){
					break;
				}
			}

			printf("%d\n", res);
		}
	}

	return 0;
}
