#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int dk[100], nk[100];
int f[100001];
int cash;

int main()
{
	int i, j, k;
	
	while(true){
		if(scanf("%d", &cash) != 1){
			break;
		}
		memset(f, 0, 100001 * sizeof(int));
		scanf("%d", &n);
		for(i = 0; i < n; ++i){
			scanf("%d%d", &nk[i], &dk[i]);
		}
		f[0] = 1;
		for(i = 0; i < n; ++i){
			for(k = cash; k >= 0; --k){
				if(f[k]){
					for(j = 1; j <= nk[i]; ++j){
						if(k + j * dk[i] <= cash){
							f[k + j * dk[i]] = 1;
						}else{
							break;
						}
					}
				}
			}
		}

		while(!f[cash]){
			--cash;
		}
		printf("%d\n", cash);
	}
	
	return 0;
}
