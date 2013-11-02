#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

char res[205][205];
bool suc;

void dfs(int a[], int sp, int rem, const int &n)
{
	int bit;

	if(suc){
		return;
	}

	if(!suc && rem == 0){
		suc = true;
		int i, j;

		j = 0;
		for(i = 0; i < sp; ++i){
			res[n][j++] = a[i] + '0';
		}
		res[n][j] = 0;

		return;
	}else if(!suc && sp < 100){
		bit = 0;
		a[sp] = bit;
		dfs(a, sp + 1, (rem * 10) % n, n);

		bit = 1;
		a[sp] = bit;
		dfs(a, sp + 1, (rem * 10 + 1) % n, n);
	}
}

void trim_zero(char str[], int n)
{
	int r2, r5;
	int r10;
	int i;

	r2 = 0;
	while(n > 0 && n % 2 == 0){
		n /= 2;
		++r2;
	}

	r5 = 0;
	while(n > 0 && n % 5 == 0){
		n /= 5;
		++r5;
	}

	r10 = (r2 > r5 ? r2 : r5);
	i = strlen(str) - 1;
	while(str[i] == '0'){
		--i;
	}
	i = i + r10 + 1;
	str[i] = 0;
}

int main()
{
	int n;
	int a[100];
	
	for(n = 1; n <= 200; ++n){
		memset(a, 0, 100 * sizeof(int));
		suc = false;
		a[0] = 1;
		dfs(a, 1, 1, n);
		trim_zero(res[n], n);
	}

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}else if(n == 0){
			break;
		}

		printf("%s\n", res[n]);
	}
	
	return 0;
}

