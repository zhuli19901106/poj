#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char a[105], b[105];
int la, lb;
int ans[105][105], aa[105], bb[105];

int main()
{
	int i, j, k;

    while(scanf("%s%s", a, b) == 2){
        la = strlen(a);
        lb = strlen(b);
        memset(ans, 0, sizeof(ans));
        memset(aa, 0, sizeof(aa));
        memset(bb, 0, sizeof(bb));
        for(i = 0; i < la; ++i){
			for(j = 0;j < lb; ++j){
				if(a[i] == b[j]){
					ans[i][j] = ans[i - 1][j - 1] + 1;
				}else{
					ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
				}
			}
		}

        i = la - 1;
        j = lb - 1;
        while(ans[i][j] != 0){
			if(a[i] == b[j] && ans[i][j] == ans[i - 1][j - 1] + 1){
               aa[i] = 1;
               bb[j] = 1;
               --i;
               --j;
			}else if(ans[i][j] == ans[i - 1][j]){
				--i;
			}else{
				--j;
			}
        }

        i = 0;
        j = 0;
		k = 0;
        for(k = 0; k < ans[la - 1][lb - 1]; ++k){
			while(aa[i] == 0){
				printf("%c", a[i]);
				++i;
			}
			while(bb[j] == 0){
				printf("%c", b[j]);
				++j;
			}
			printf("%c", a[i]);
			++i;
			++j;
		}
		while(i < la){
			printf("%c", a[i]);
			++i;
		}
		while(j < lb){
			printf("%c", b[j]);
			++j;
		}
		printf("\n");
	}

	return 0;
}

