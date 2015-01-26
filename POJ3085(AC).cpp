#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int case_count;
	int case_no;
	int n;
	const int v[4] = {25, 10, 5, 1};
	int f[501][4];
	int i, j;
	
	memset(f, 0, 501 * 4 * sizeof(int));
	for(i = 0; i <= 500; ++i){
		n = i;
		for(j = 0; j <= 3; ++j){
			if(0 == n){
				break;
			}else{
				f[i][j] = n /v[j];
				n %= v[j];
			}
		}
	}
	
	while(true){
		if(scanf("%d", &case_count) != 1){
			break;
		}
		for(case_no = 1; case_no <= case_count; ++case_no){
			scanf("%d", &n);
			printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", case_no, f[n][0], f[n][1], f[n][2], f[n][3]);
		}
	}
	
	return 0;
}
