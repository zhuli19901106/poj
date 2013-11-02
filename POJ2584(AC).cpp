#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX 120
int map[MAX][MAX];
int used[MAX], mat[MAX];

int Augment(int m, int x)
{
	int i;

	for(i = 1; i <= m; i++){
		if(!used[i] && map[x][i]){
			used[i] = 1;
			if(!mat[i] || Augment(m, mat[i])){
				mat[i] = x;
				return 	1;
			}
		}
	}
	
	return 0;
}

int Hungary(int n, int m)
{
	memset(mat, 0, sizeof(mat));
	int i,sum = 0;
	for(i = 1; i <= n; i++){
		memset(used, 0, sizeof(used));
		if(Augment(m, i)){
			sum++;
		}
	}
	
	return sum;
}

int main()
{
	char T[] = {"1SMLXT"};
	char START[100], END[100];
	char t[30][5];
	int nt[30], start[30];
	int n;
	int i, k;
	
	while(~scanf("%s",START) && strcmp(START,"ENDOFINPUT")){
		memset(map,0,sizeof(map));
		scanf("%d",&n);
		for(i = 1; i <= n; i++)
			scanf("%s", t[i]);
	
		int beg = 0;
		for(i = 1; i <= 5; i++)
		{
			scanf("%d", &nt[i]);
			start[i] = beg + 1;
			beg += nt[i];
		}
		scanf("%s", END);
		int s, e;
		for(i = 1; i <= n; i++){
			for(k = 1; k <= 5; k++){
				if(T[k] == t[i][0]){
					s = k;
				}
				if(T[k] == t[i][1]){
					e = k;
				}
			}
			for(k = start[s]; k < start[e] + nt[e]; k++){
				map[i][k] = 1;
			}
		}
		
		int ans = Hungary(n, beg);
		if(ans == n){
			printf("T-shirts rock!\n");
		}else{
			printf("I'd rather not wear a shirt anyway...\n");
		}
	}
	return 0;

}

