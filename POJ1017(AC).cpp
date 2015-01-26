#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a[7];
	int sum;
	
	while(scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]) == 6 && (a[1] + a[2] + a[3] + a[4] + a[5] + a[6])){
		sum = 0;

		sum += a[6];

		sum += a[5];
		a[1] -= 11 * a[5];
		if(a[1] < 0){
			a[1] = 0;
		}
		
		sum += a[4];
		if(a[2] >= a[4] * 5){
			a[2] -= a[4] * 5;
		}else{
			a[1] -= 4 * (a[4] * 5 - a[2]);
			if(a[1] < 0){
				a[1] = 0;
			}
			a[2] = 0;
		}
		
		sum += (a[3] + 3) / 4;
		a[3] %= 4;
		if(a[3]){
			if(a[2] >= 7 - 2 * a[3]){
				a[2] -= 7 - 2 * a[3];
				a[1] -= 8 - a[3];
				if(a[1] < 0){
					a[1] = 0;
				}
			}else{
				a[1] -= 36 - a[3] * 9 - a[2] * 4;
				if(a[1] < 0){
					a[1] = 0;
				}
				a[2] = 0;
			}
		}

		sum += (a[2] + 8) / 9;
		a[2] %= 9;
		if(a[2]){
			a[1] -= 36 - a[2] * 4;
			if(a[1] < 0){
				a[1] = 0;
			}
		}

		sum += (a[1] + 35) / 36;
		
		printf("%d\n", sum);
	}
	
	return 0;
}
