#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a3[15];
int a4[15];

int main()
{
	int i;
	int n;
	int tmp, min;
	
	a3[0] = 0;
	for(i = 1; i < 15; ++i){
		a3[i] = 2 * a3[i - 1] + 1;
	}
	
	a4[0] = 0;
	a4[1] = 1;
	for(n = 2; n <= 15; ++n){
		min = -1;
		for(i = 1; i < n; ++i){
			tmp = 2 * a4[i] + a3[n - i];
			if(min == -1 || tmp < min){
				min = tmp;
			}
		}
		a4[n] = min;
	}
	
	for(n = 1; n <= 12; ++n){
		printf("%d\n", a4[n]);
	}
	
	return 0;
}

