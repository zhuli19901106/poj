#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int res;
	int a;
	int i, m;

	while(scanf("%d", &m) == 1){
		res = 0;
		for(i = 0; i < m; ++i){
			scanf("%d", &a);
			res ^= a;
		}
		if(res){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}

