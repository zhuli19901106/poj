#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1024;
int c[MAXN + 1][MAXN + 1];
int n;

int low_bit(int x)
{
	return x & (-x);
}

void add_value(int i, int j, int v, int n)
{
	int j1;

	while(i <= n){
		j1 = j;
		while(j1 <= n){
			c[i][j1] += v;
			j1 += low_bit(j1);
		}
		i += low_bit(i);
	}
}

int get_sum(int i, int j)
{
	int j1;
	int sum;

	if(i <= 0 || j <= 0){
		return 0;
	}

	sum = 0;
	while(i > 0){
		j1 = j;
		while(j1 > 0){
			sum += c[i][j1];
			j1 -= low_bit(j1);
		}
		i -= low_bit(i);
	}

	return sum;
}

int partial_sum(int x1, int y1, int x2, int y2)
{
	return get_sum(x2, y2) + get_sum(x1 - 1, y1 - 1) - get_sum(x2, y1 - 1) - get_sum(x1 - 1, y2);
}

int main()
{
	int op;
	int x1, y1, x2, y2, v;

	memset(c, 0, (MAXN + 1) * (MAXN + 1) * sizeof(int));
	while(scanf("%d", &op) == 1){
		if(op == 0){
			scanf("%d", &n);
		}else if(op == 1){
			scanf("%d%d%d", &x1, &y1, &v);
			++x1;
			++y1;
			add_value(x1, y1, v, n);
		}else if(op == 2){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			++x1;
			++y1;
			++x2;
			++y2;
			printf("%d\n", partial_sum(x1, y1, x2, y2));
		}else if(op == 3){
			break;
		}
	}

	return 0;
}

