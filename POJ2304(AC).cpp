#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, a, b, c;
	int sum;

	while(scanf("%d%d%d%d", &n, &a, &b, &c) == 4 && (n || a || b || c)){
		sum = 1080;
		if(n >= a){
			sum += (n - a) * 9;
		}else{
			sum += (40 - (a - n)) * 9;
		}

		if(a <= b){
			sum += (b - a) * 9;
		}else{
			sum += (40 - (a - b)) * 9;
		}

		if(b >= c){
			sum += (b - c) * 9;
		}else{
			sum += (40 - (c - b)) * 9;
		}

		printf("%d\n", sum);
	}

	return 0;
}
