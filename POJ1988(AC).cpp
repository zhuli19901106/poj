#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct st{
	int r;
	int u;
	int d;
}st;
st a[30010];
int b[30010];
int bc;

int find_root(int x)
{
	int r;
	int k;
	int i;
	
	k = x;
	bc = 0;
	while(a[k].r != k){
		b[bc++] = k;
		k = a[k].r;
	}
	r = k;
	b[bc++] = r;

	for(i = bc - 2; i >= 0; --i){
		a[b[i]].r = r;
		a[b[i]].u = a[b[i]].u + a[b[i + 1]].u;
		a[b[i]].d = a[b[i + 1]].d - (a[b[i]].u - a[b[i + 1]].u);
	}

	return r;
}

int main()
{
	int n, ni;
	int i;
	int x, y;
	int rx, ry;
	char s[20];
	
	while(scanf("%d", &n) == 1){
		for(i = 0; i < 30010; ++i){
			a[i].r = i;
			a[i].u = 0;
			a[i].d = 0;
		}
		for(ni = 1; ni <= n; ++ni){
			scanf("%s", s);
			if(s[0] == 'M'){
				scanf("%d%d", &x, &y);
				rx = find_root(x);
				ry = find_root(y);
				a[ry].r = rx;
				a[ry].u = a[rx].d + 1;
				a[rx].d = a[rx].d + a[ry].d + 1;
				find_root(x);
				find_root(y);
			}else if(s[0] == 'C'){
				scanf("%d", &x);
				find_root(x);
				printf("%d\n", a[x].d);
			}
		}
	}
	
	return 0;
}
