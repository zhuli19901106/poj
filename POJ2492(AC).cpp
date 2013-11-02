/*
Memory 144K
Time  750MS
*/

#include <stdio.h>
#define MAXV 2010

int flag,m,n,ans[MAXV],tree[MAXV];

void init(){
    int i;
    for(i=1;i<=n;i++){
        ans[i]=0;
        tree[i]=i;
    }
    flag=1;
}

int find(int x){
    int rt;
    if(x!=tree[x]){
        rt=find(tree[x]);
        ans[x]=ans[x]^ans[tree[x]];
        return tree[x]=rt;
    }
    return x;
}

void TUnion(int x,int y){
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if(fx==fy)
        flag=ans[x]^ans[y];
    else{
        tree[fx]=fy;
        ans[fx]=~(ans[x]^ans[y]);
    }
}

int main(){
    int i,j,t,a,b;
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        scanf("%d%d",&n,&m);
        init();
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            if(flag){
                TUnion(a,b);
            }
        }
        printf("Scenario #%d:\n",j);
        if(flag)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");
    }
    return 0;
}

