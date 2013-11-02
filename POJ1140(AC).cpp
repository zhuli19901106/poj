#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 2000;
int vis[MAXN];
char ans[MAXN];

int main()
{
    int n, d;
	int now, i, res;

    while(scanf("%d%d",&n,&d) == 2 && (n || d)){
        now = n;
        bool yes=false;
        int end=0;
        memset(vis, 0, sizeof(vis));
        
		ans[0] = '.';
        for(i = 2; ; i++){
            if(now == 0){
                yes = true;
                break;
            }
            if(vis[now]){
                res = i - vis[now];
                break;
            }
            vis[now] = i;
            ans[++end] = now * 10 / d + '0';
            now = now * 10 - (ans[end] - '0') * d;
            if(i % 50 == 0){
                ans[++end] = '\n';
			}
        }
        if((i-1) % 50 == 0){
            ans[end] = 0;
		}else{
            ans[++end] = 0;
		}
        puts(ans);

        if(yes){
            puts("This expansion terminates.");
		}else{
            printf("The last %d digits repeat forever.\n", res);
		}
    }

    return 0;
}

