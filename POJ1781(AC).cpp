#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

//Joseph Problem, O(n) still TLE

int f(int n)
{
	if(n < 1){
		return 0;
	}else if(n == 1){
		return 1;
	}else if(n % 2 == 0){
		return 2 * f(n / 2) - 1;
	}else{
		return 2 * f(n / 2) + 1;
	}
}

int main()
{
	int n;
	char str[1000];
	int x, y, z;
	
	while(gets(str) != NULL){
		x = str[0] - '0';
		y = str[1] - '0';
		z = str[3] - '0';
		if(0 == x && 0 == y && 0 == z){
			break;
		}
		n = x * 10 + y;
		while(z--){
			n = n * 10;
		}

		printf("%d\n", f(n));
	}
	
	return 0;
}

