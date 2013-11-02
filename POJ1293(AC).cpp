#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int M, L;
int n;
int f[2001];
int c[2001];
int path[2001];
int sum;

void print_recursive(int sum, int count)
{
	if(sum > c[path[sum]]){
		print_recursive(sum - c[path[sum]], count + 1);
		printf(" %d", path[sum]);
	}else{
		printf("%d %d", count, path[sum]);
	}
}

int main()
{
	int i, j;
	
	while(true){
		if(scanf("%d%d", &M, &L) != 2){
			break;
		}else if(0 == M && 0 == L){
			break;
		}
		
		scanf("%d", &n);
		sum = 0;
		memset(c, 0, 2001 * sizeof(int));
		for(i = 1; i <= n; ++i){
			scanf("%d", &c[i]);
			sum += c[i];
		}
		
		if(sum > M + L){
			printf("Impossible to distribute\n");
			continue;
		}
		
		memset(f, 0, 2001 * sizeof(int));
		memset(path, 0, 2001 * sizeof(int));
		f[0] = 1;
		for(i = 1; i <= n; ++i){
			for(j = M; j >= c[i]; --j){
				if(f[j - c[i]] && !f[j]){
					f[j] = 1;
					path[j] = i;
				}
			}
		}
		
		for(i = 0; i <= M; ++i){
			if(f[i] && sum - i <= L){
				break;
			}
		}
		
		if(i == 0){
			printf("0\n");
		}else if(i == M + 1){
			printf("Impossible to distribute\n");
		}else{
			print_recursive(i, 1);
			printf("\n");
		}
	}
	
	return 0;
}

