#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
	int s, e, id;
}st;

bool comparator(st &x, st &y)
{
	if(x.e == y.e){
		return x.s < y.s;
	}else{
		return x.e > y.e;
	}
}

const int MAXN = 100005;
st v[MAXN + 1];
int a[MAXN + 1];
int c[MAXN + 1];
int n;

int low_bit(int x)
{
	return x & (-x);
}

void add_value(int i, int x)
{
	while(i <= MAXN){
		a[i] += x;
		i += low_bit(i);
	}
}

int get_sum(int i)
{
	int sum;

	sum = 0;
	while(i > 0){
		sum += a[i];
		i -= low_bit(i);
	}

	return sum;
}

int main()
{
	int i;

	while(scanf("%d", &n) == 1 && n){
		for(i = 1; i <= n; ++i){
			scanf("%d%d", &v[i].s, &v[i].e);
			++v[i].s;
			++v[i].e;
			v[i].id = i;
		}
		memset(a, 0, (MAXN + 1) * sizeof(int));
		memset(c, 0, (MAXN + 1) * sizeof(int));
		sort(v + 1, v + n + 1, comparator);
		for(i = 1; i <= n; ++i){
			if(v[i].s == v[i - 1].s && v[i].e == v[i - 1].e){
				c[v[i].id] = c[v[i - 1].id];
			}else{
				c[v[i].id] = get_sum(v[i].s);
			}
			add_value(v[i].s, 1);
		}
		for(i = 1; i < n; ++i){
			printf("%d ", c[i]);
		}
		printf("%d\n", c[n]);
	}

	return 0;
}
