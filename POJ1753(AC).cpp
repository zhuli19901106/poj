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
int n, res;
queue<int> q;

int main()
{
	char s[10];
	int i, j;

	a[0] = b[0] | b[1] | b[4];
	a[1] = b[0] | b[1] | b[2] | b[5];
	a[2] = b[1] | b[2] | b[3] | b[6];
	a[3] = b[2] | b[3] | b[7];
	a[4] = b[0] | b[4] | b[5] | b[8];
	a[5] = b[1] | b[4] | b[5] | b[6] | b[9];
	a[6] = b[2] | b[5] | b[6] | b[7] | b[10];
	a[7] = b[3] | b[6] | b[7] | b[11];
	a[8] = b[4] | b[8] | b[9] | b[12];
	a[9] = b[5] | b[8] | b[9] | b[10] | b[13];
	a[10] = b[6] | b[9] | b[10] | b[11] | b[14];
	a[11] = b[7] | b[10] | b[11] | b[15];
	a[12] = b[8] | b[12] | b[13];
	a[13] = b[9] | b[12] | b[13] | b[14];
	a[14] = b[10] | b[13] | b[14] | b[15];
	a[15] = b[11] | b[14] | b[15];

	n = 0;
	for(i = 0; i < 4; ++i){
		scanf("%s", s);
		for(j = 0; j < 4; ++j){
			if(s[j] == 'w'){
				n = n | b[(4 * i + j)];
			}
		}
	}

	while(!q.empty()){
		q.pop();
	}

	memset(f, 0, 65536 * sizeof(int));
	f[n] = 1;
	q.push(n);

	while(!q.empty()){
		if(f[0] || f[65535]){
			break;
		}

		n = q.front();
		q.pop();

		for(i = 0; i < 16; ++i){
			if(!f[n ^ a[i]]){
				f[n ^ a[i]] = f[n] + 1;
				q.push(n ^ a[i]);
			}
		}
	}

	if(f[0]){
		if(f[65535]){
			printf("%d\n", (f[0] < f[65535] ? f[0] : f[65535]) - 1);
		}else{
			printf("%d\n", f[0] - 1);
		}
	}else{
		if(f[65535]){
			printf("%d\n", f[65535] - 1);
		}else{
			printf("Impossible\n");
		}
	}

	while(!q.empty()){
		q.pop();
	}

	return 0;
}

