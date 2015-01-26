#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, a[100], tmp;
	int i, j;
	int upsum, upcount;
	int downsum, downcount;
	int flag;
	
	while(true){
		n = 0;
		if(scanf("%d", &tmp) != 1){
			break;
		}else if(tmp == 0){
			break;
		}else{
			a[n] = tmp;
			++n;
			while(true){
				scanf("%d", &tmp);
				if(tmp == 0){
					break;
				}else{
					a[n] = tmp;
					++n;
				}
			}
		}
		upsum = 0;
		downsum = 0;
		upcount = 0;
		downcount = 0;
		
		i = 0;
		while(i + 1 < n && a[i] == a[i + 1]){
			++i;
		}
		
		if(i + 1 < n){
			//There is at least one sequence
			if(a[i] < a[i + 1]){
				j = i + 1;
				i = 0;
				flag = +1;
			}else if(a[i] > a[i + 1]){
				j = i + 1;
				i = 0;
				flag = -1;
			}
			while(true){
				if(j + 1 >= n){
					if(flag == +1){
						upsum += (j - i);
						++upcount;
					}else if(flag == -1){
						downsum += (j - i);
						++downcount;
					}
					break;
				}
				if(flag == +1){
					if(a[j] <= a[j + 1]){
						++j;
					}else{
						upsum += (j - i);
						++upcount;
						flag = -1;
						i = j;
						j = j + 1;
					}
				}else if(flag == -1){
					if(a[j] >= a[j + 1]){
						++j;
					}else{
						downsum += (j - i);
						++downcount;
						flag = +1;
						i = j;
						j = j + 1;
					}
				}
			}
		}
		
		printf("Nr values = %d:  ", n);
		if(upsum == 0){
			printf("%.6f ", 0.0);
		}else{
			printf("%.6f ", 1.0 * upsum / upcount);
		}
		if(downsum == 0){
			printf("%.6f\n", 0.0);
		}else{
			printf("%.6f\n", 1.0 * downsum / downcount);
		}
	}
	
	return 0;
}
