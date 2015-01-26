#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, r;
	int p, c;
	int ri;
	int i;
	int card[100];
	int tmp[100];
	
	while(true){
		if(scanf("%d%d", &n, &r) != 2){
			break;
		}else if(0 == n && 0 == r){
			break;
		}
		
		
		for(i = 1; i <= n; ++i){
			card[i] = n + 1 - i;
		}
		
		for(ri = 0; ri < r; ++ri){
			scanf("%d%d", &p, &c);
			for(i = 1; i <= p - 1; ++i){
				tmp[i + c] = card[i];
			}
			for(i = p; i <= p + c - 1; ++i){
				tmp[i - p + 1] = card[i];
			}
			for(i = 1; i <= p + c - 1; ++i){
				card[i] = tmp[i];
			}
		}
		
		printf("%d\n", card[1]);
	}
	
	return 0;
}
