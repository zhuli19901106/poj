#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int a[100][2];
int ac;
int b[100][2];
int bc;
int c[100][2];
int cc;

int p[2000];
int pc;

int bb[10001];

int main()
{
	int n, ni, i, j;
	
	memset(bb, 0, 10001 * sizeof(int));
	bb[0] = bb[1] = 1;
	for(i = 2; i * i <= 10000; ++i){
		if(bb[i]){
			continue;
		}
		for(j = i; i * j <= 10000; ++j){
			bb[i * j] = 1;
		}
	}
	pc = 0;
	for(i = 1; i <= 10000; ++i){
		bb[i] = !bb[i];
		if(bb[i]){
			p[pc++] = i;
		}
	}
	
	memset(a, 0, 100 * 2 * sizeof(int));
	memset(b, 0, 100 * 2 * sizeof(int));
	memset(c, 0, 100 * 2 * sizeof(int));
	ac = bc = cc = 0;

	for(ni = 0; ni < 10; ++ni){
		scanf("%d", &n);
		if(n == 1){
			continue;
		}
		j = 0;
		bc = 0;
		while(true){
			if(p[j] * p[j] > n){
				break;
			}else if(n % p[j] == 0){
				b[bc][0] = p[j];
				b[bc][1] = 0;
				while(n % p[j] == 0){
					n /= p[j];
					++b[bc][1];
				}
				++bc;
				++j;
			}else{
				++j;
			}
		}
		if(n > 1){
			b[bc][0] = n;
			b[bc][1] = 1;
			++bc;
			n = 1;
		}
		
		memset(c, 0, 100 * 2 * sizeof(int));
		i = j = cc = 0;
		while(i < ac && j < bc){
			if(a[i][0] < b[j][0]){
				c[cc][0] = a[i][0];
				c[cc][1] = a[i][1];
				++i;
			}else if(a[i][0] == b[j][0]){
				c[cc][0] = a[i][0];
				c[cc][1] = a[i][1] + b[j][1];
				++i;
				++j;
			}else{
				c[cc][0] = b[j][0];
				c[cc][1] = b[j][1];
				++j;
			}
			++cc;
		}
		while(i < ac){
			c[cc][0] = a[i][0];
			c[cc][1] = a[i][1];
			++i;
			++cc;
		}
		while(j < bc){
			c[cc][0] = b[j][0];
			c[cc][1] = b[j][1];
			++j;
			++cc;
		}

		memcpy(a, c, 100 * 2 * sizeof(int));
		ac = cc;
	}

	int res;

	res = 1;
	for(i = 0; i < ac; ++i){
		res = res * (a[i][1] + 1) % 10;
	}
	printf("%d\n", res);

	return 0;
}
