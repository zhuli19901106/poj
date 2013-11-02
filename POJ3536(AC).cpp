#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, a, b, c;
int maxa;

void swap(int &x, int &y)
{
	int t;

	t = x;
	x = y;
	y = t;
}

int main()
{
	int i, j, k, rt1, rt2, sum;

	while(scanf("%d", &n) == 1){
		maxa = 2147483647;

		rt1 = (int)sqrt(n * 1.0);
		for(i = 1; i <= rt1 + 1; ++i){
			if(n % i == 0){
				rt2 = (int)sqrt(n / i * 1.0);
				for(j = i; j <= rt2 + 1; ++j){
					if(n / i % j == 0){
						k = n / i / j;
						sum = 2 * (i * j + j * k + k * i);
						if(sum < maxa){
							maxa = sum;
							a = i;
							b = j;
							c = k;
						}
					}
				}
			}
		}

		if(a > b){
			swap(a, b);
		}
		if(a > c){
			swap(a, c);
		}
		if(b > c){
			swap(b, c);
		}
		printf("%d %d %d\n", a, b, c);
	}

	return 0;
}

