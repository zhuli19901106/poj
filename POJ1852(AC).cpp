#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int case_count;
	int case_no;
	int i, n;
	double len;
	double pos;
	double max_t, min_t;
	double max_pos;
	double min_pos;
	double mid_pos;
	double mid;
	
	while(true){
		if(scanf("%d", &case_count) != 1){
			break;
		}
		for(case_no = 0; case_no < case_count; ++case_no){
			max_t = -1;
			min_t = 1000005;
			max_pos = -1;
			min_pos = 1000005;
			mid_pos = -1;
			scanf("%lf%d", &len, &n);
			mid = len / 2;
			for(i = 0; i < n; ++i){
				scanf("%lf", &pos);
				if(pos < min_pos){
					min_pos = pos;
				}
				if(pos > max_pos){
					max_pos = pos;
				}
				if(fabs(pos - mid) < fabs(mid_pos - mid)){
					mid_pos = pos;
				}
			}
			
			min_t = mid - fabs(mid_pos - mid);
			max_t = max_pos > len - min_pos ? max_pos : len - min_pos;
			printf("%d %d\n", (int)min_t, (int)max_t);
		}
	}

	return 0;
}

