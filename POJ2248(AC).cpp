#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[101];
int c[101];
int n;
int len;

void dfs(int cc)
{
	int i;

	if(cc > len){
		return;
	}
	if(c[cc - 1] == n){
		if(cc < len){
			len = cc;
			for(i = 0; i < len; ++i){
				a[i] = c[i];
			}
		}
		return;
	}

	for(i = cc - 1; i >= 0; --i){
		c[cc] = c[cc - 1] + c[i];
		if(c[cc] > n){
			continue;
		}
		dfs(cc + 1);
	}
}

const int mymin(const int &a, const int &b)
{
	return (a < b ? a : b);
}

int main()
{
	int i;

	while(scanf("%d", &n) == 1 && n){
		if(n == 1){
			printf("1\n");
			continue;
		}

		len = 20;
		c[0] = 1;
		dfs(1);

		for(i = 0; i < len; ++i){
			if(i == 0){
				printf("%d", a[i]);
			}else{
				printf(" %d", a[i]);
			}
		}
		printf("\n");
	}

	return 0;
}
