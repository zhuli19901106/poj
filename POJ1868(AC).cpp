#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 10005;
int a[MAXN];
int b[MAXN];
int n;

int main()
{
	int i, j;
	bool antiarith;
	char s[5];

	while(scanf("%d", &n) == 1 && n){
		scanf("%1s", s);
		memset(a, 0, MAXN * sizeof(int));
		memset(b, 0, MAXN * sizeof(int));
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			b[a[i]] = i;
		}

		antiarith = true;
		for(i = 0; i < n - 2; ++i){
			for(j = i + 2; j < n; ++j){
				if((a[i] + a[j]) % 2 == 0){
					if(b[(a[i] + a[j]) / 2] > i && b[(a[i] + a[j]) / 2] < j){
						antiarith = false;
					}
				}
				if(!antiarith){
					break;
				}
			}
			if(!antiarith){
				break;
			}
		}

		if(antiarith){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}
