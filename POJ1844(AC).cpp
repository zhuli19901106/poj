#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int sum, s;
	int n;

	while(scanf("%d", &s) == 1){
		sum = 0;
		n = 1;

		while(sum < s || (sum - s) % 2){
			sum += n;
			++n;
		}
		printf("%d\n", --n);
	}

	return 0;
}
