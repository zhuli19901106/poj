#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int f[32][32];
int G, L;

int main()
{
	int i, j;
	int case_count;
	
	memset(f, 0, 32 * 32 * sizeof(int));
	for(i = 0; i <= 30; ++i){
		f[i][0] = i;
		f[0][i] = 0;
	}

	for(i = 1; i <= 30; ++i){
		for(j = 1; j <= 30; ++j){
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j] + 1;
		}
	}

	case_count = 0;
	while(true){
		if(scanf("%d%d", &G, &L) != 2){
			break;
		}else if(G == 0 && L == 0){
			break;
		}else{
			++case_count;
		}
		printf("Case %d: %d\n", case_count, f[G][L]);
	}
	
	return 0;
}
