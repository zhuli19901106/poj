#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int dj[105];
double p[105][2];
int pc;
typedef struct st{
	int a;
	int b;
	double d;
}st;
st e[10005];
int ec;

double dist(const double p1[], const double p2[])
{
	return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
}

bool comparator(const st &x, const st &y)
{
	if(x.d == y.d){
		if(x.a == y.a){
			return x.b < y.b;
		}else{
			return x.a < y.a;
		}
	}else{
		return x.d < y.d;
	}
}

int find_root(int x)
{
	int k, r;

	r = x;
	while(dj[r] != r){
		r = dj[r];
	}

	k = x;
	while(k != r){
		k = dj[x];
		dj[x] = r;
		x = k;
	}

	return r;
}

int main()
{
	int i, j;
	int ra, rb;
	double min_len;

	while(scanf("%d", &pc) == 1){
		for(i = 0; i < pc; ++i){
			scanf("%lf%lf", &p[i][0], &p[i][1]);
		}
		for(i = 0; i < pc - 1; ++i){
			for(j = i + 1; j < pc; ++j){
				e[ec].a = i;
				e[ec].b = j;
				e[ec].d = dist(p[i], p[j]);
				++ec;
			}
		}
		sort(e, e + ec, comparator);
		for(i = 0; i < pc; ++i){
			dj[i] = i;
		}

		min_len = 0;
		for(i = 0; i < ec; ++i){
			ra = find_root(e[i].a);
			rb = find_root(e[i].b);
			if(ra != rb){
				dj[ra] = rb;
				find_root(e[i].a);
				find_root(e[i].b);
				min_len += e[i].d;
				--pc;
				if(pc == 1){
					break;
				}
			}
		}
		printf("%.2f\n", min_len);
	}

	return 0;
}
