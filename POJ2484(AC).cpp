#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int n;

	while(scanf("%d", &n) == 1 && n){
		if(n <= 2){
			printf("Alice\n");
		}else if(n >= 3){
			printf("Bob\n");
		}
	}

	return 0;
}

