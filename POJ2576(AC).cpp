#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool dp[55][24750];
int w[101];
int sum;
int half;

int main()
{
	int i, j;
	int k;
	int n;
	int num;
	
	while(true){
		memset(dp, 0, 55 * 24750 * sizeof(bool));
		if(scanf("%d", &n) == 1){
			sum = 0;
			for(i = 0; i < n; i++){
				scanf("%d", &w[i]);
				sum = sum + w[i];
			}
			half = sum / 2;
			
			num = (n + 1) / 2;
			for(i = 0; i <= num; i++){
				dp[i][0] = true;
			}
			for(i = 0; i < n; i++){
				for(j = 0; j < num; j++){
					k = 0;
					while(k + w[i] <= half){
						if(dp[j][k] && !dp[j + 1][k + w[i]]){
							dp[j + 1][k + w[i]] = true;
						}
						k++;
					}
				}
			}
			
			for(i = half; !dp[num][i]; i--){
				;
			}
			printf("%d %d\n", i, sum - i);
		}else{
			break;
		}
	}
	
	return 0;
}
