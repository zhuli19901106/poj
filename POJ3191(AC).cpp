#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int a[1000];
int ac;

int myabs(const int n)
{
	return (n > 0 ? n : -n);
}

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		if(n == 0){
			printf("0\n");
			continue;
		}
		ac = 0;
		while(n != 1){
			if(myabs(n) % 2){
				a[ac++] = 1;
				n = (n - 1) / (-2);
			}else{
				a[ac++] = 0;
				n = n / -2;
			}
		}
		printf("1");
		for(i = ac - 1; i >= 0; --i){
			printf("%d", a[i]);
		}
		printf("\n");
	}

	return 0;
}
