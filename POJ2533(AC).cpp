#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int tmp;
	int i, j;
	int n;
	int a[2000];
	int max_len;
	const int MAX = 20000;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		max_len = 0;
		for(i = 1; i <= n; ++i){
			scanf("%d", &tmp);
			a[i] = MAX;
			for(j = 1; a[j] < tmp; ++j){
				;
			}
			a[j] = tmp;
			if(max_len < j){
				max_len = j;
			}
		}
		
		printf("%d\n", max_len);
	}
	
	return 0;
}
