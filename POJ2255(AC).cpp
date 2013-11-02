#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char pre[100];
char ino[100];
int a[26][2];
int len;

void post_order(int r)
{
	if(a[r][0] != -1 && a[r][0] != r){
		post_order(a[r][0]);
	}
	if(a[r][1] != -1 && a[r][1] != r){
		post_order(a[r][1]);
	}
	printf("%c", r + 'A');
}

void construct(int p1, int p2, int i1, int i2)
{
	int ri;

	for(ri = i1; ri <= i2; ++ri){
		if(ino[ri] == pre[p1]){
			break;
		}
	}

	if(ri > i1){
		//left subtree exists
		a[ino[ri] - 'A'][0] = pre[p1 + 1] - 'A';
		construct(p1 + 1, p1 + ri - i1, i1, ri - 1);
	}

	if(ri < i2){
		//right subtree exists
		a[ino[ri] - 'A'][1] = pre[p1 + 1 + ri - i1] - 'A';
		construct(p1 + 1 + ri - i1, p2, ri + 1, i2);
	}
}

int main()
{
	int r;
	int i;

	while(scanf("%s%s", pre, ino) == 2){
		r = pre[0] - 'A';
		len = strlen(pre);
		for(i = 0; i < 26; ++i){
			a[i][0] = -1;
			a[i][1] = -1;
		}
		construct(0, len - 1, 0, len - 1);
		post_order(r);
		printf("\n");
	}

	return 0;
}

