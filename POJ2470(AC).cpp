#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	const int MAXN = 100001;
	int a[MAXN];
	int b[MAXN];
	int i, n;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}else if(n <= 0){
			break;
		}
		memset(a, 0, MAXN * sizeof(int));
		memset(b, 0, MAXN * sizeof(int));
		
		for(i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			b[a[i]] = i;
		}
		
		for(i = 1; i <= n; ++i){
			if(a[i] != b[i]){
				break;
			}
		}
		
		if(i == n + 1){
			printf("ambiguous\n");
		}else{
			printf("not ambiguous\n");
		}
	}
	
	return 0;
}

