#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int getsum(int n)
{
	int dsum;
	int n0;

	n0 = n;
	dsum = 0;
	while(n > 0)
	{
		dsum += n % 10;
		n = n / 10;
	}

	return n0 + dsum;
}
int a[10000];

int main()
{
	int i;
	int sum;

	memset(a, 0, 10000 * sizeof(int));
	for(i = 1; i < 10000; i++){
		sum = getsum(i);
		if(sum < 10000){
			a[sum] = 1;
		}
	}

	for(i = 1; i < 10000; i++){
		if(!a[i]){
			printf("%d\n", i);
		}
	}

	return 0;
}

