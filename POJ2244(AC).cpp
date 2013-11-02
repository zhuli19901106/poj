#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[200];
int n, m;

int main()
{
	int i, f;
	
	while(scanf("%d", &n) == 1 && n){
		m = 1;
		while(true){
			f = 0;
			for(i = 2; i <= n; ++i){
				f = (f + m) % i;
			}
			if(f == (m % n)){
				break;
			}else{
				++m;
			}
		}
		printf("%d\n", m);
	}

	return 0;
}

