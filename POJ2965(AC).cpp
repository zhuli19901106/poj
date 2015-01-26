#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

const int b[16] = {
	0x1, 0x2, 0x4, 0x8, 
	0x10, 0x20, 0x40, 0x80, 
	0x100, 0x200, 0x400, 0x800, 
	0x1000, 0x2000, 0x4000, 0x8000
};
int a[16];

int f[65536];
int p[65536];
int c[100], cp;
int n, res;
queue<int> q;

int main()
{
	char s[10];
	int i, j, k;
	
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			a[4 * i + j] = 0;
			for(k = 0; k < 4; ++k){
				a[4 * i + j] |= b[4 * k + j];
				a[4 * i + j] |= b[4 * i + k];
			}
		}
	}

	n = 0;
	for(i = 0; i < 4; ++i){
		scanf("%s", s);
		for(j = 0; j < 4; ++j){
			if(s[j] == '+'){
				n = n | b[(4 * i + j)];
			}
		}
	}

	while(!q.empty()){
		q.pop();
	}

	memset(f, 0, 65536 * sizeof(int));
	f[n] = 1;
	p[n] = n;
	q.push(n);

	while(!q.empty()){
		if(f[0]){
			break;
		}

		n = q.front();
		q.pop();

		for(i = 0; i < 16; ++i){
			if(!f[n ^ a[i]]){
				f[n ^ a[i]] = f[n] + 1;
				p[n ^ a[i]] = n;
				q.push(n ^ a[i]);
			}
		}
	}

	if(f[0]){
		cp = 0;
		n = 0;
		while(p[n] != n){
			c[cp++] = n;
			n = p[n];
		}
		c[cp++] = n;
		printf("%d\n", cp - 1);
		for(i = cp - 1; i > 0; --i){
			for(j = 0; j < 16; ++j){
				if((c[i] ^ c[i - 1]) == a[j]){
					printf("%d %d\n", j / 4 + 1, j % 4 + 1);
					break;
				}
			}
		}
	}else{
		printf("Impossible\n");
	}

	while(!q.empty()){
		q.pop();
	}

	return 0;
}
