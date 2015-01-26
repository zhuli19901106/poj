#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	double p[4][2];
	
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p[0][0], &p[0][1], &p[1][0], &p[1][1], &p[2][0], &p[2][1], &p[3][0], &p[3][1]) == 8){
		if(p[0][0] == p[2][0] && p[0][1] == p[2][1]){
			printf("%.3f %.3f\n", p[1][0] + p[3][0] - p[0][0], p[1][1] + p[3][1] - p[0][1]);
		}else if(p[0][0] == p[3][0] && p[0][1] == p[3][1]){
			printf("%.3f %.3f\n", p[1][0] + p[2][0] - p[0][0], p[1][1] + p[2][1] - p[0][1]);
		}else if(p[1][0] == p[2][0] && p[1][1] == p[2][1]){
			printf("%.3f %.3f\n", p[0][0] + p[3][0] - p[1][0], p[0][1] + p[3][1] - p[1][1]);
		}else{
			printf("%.3f %.3f\n", p[0][0] + p[2][0] - p[1][0], p[0][1] + p[2][1] - p[1][1]);
		}
	}

	return 0;
}
