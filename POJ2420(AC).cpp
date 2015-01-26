#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
double p[105][2];
double sum0;
double p0[2];
double step;

double dist(const double p1[], const double p2[])
{
	if((p1[0] != p2[0]) || (p1[1] != p2[1])){
		return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
	}else{
		return 0.0;
	}
}

double sum_dist(const double p0[], const double p[][2], const int n)
{
	double sum;
	int i;

	sum = 0.0;
	for(i = 0; i < n; ++i){
		sum += dist(p0, p[i]);
	}

	return sum;
}

int min_index(const double a[], int n)
{
	int i;
	int mini;

	mini = 0;
	for(i = 1; i < n; ++i){
		if(a[i] < a[mini]){
			mini = i;
		}
	}

	return mini;
}

int main()
{
	int i;
	int mini;
	double p1[4][2];
	double sum1[4];

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%lf%lf", &p[i][0], &p[i][1]);
		}
		p0[0] = p[0][0];
		p0[1] = p[0][1];
		sum0 = sum_dist(p0, p, n);
		step = 10001;
		while(true){
			p1[0][0] = p0[0] - step;
			p1[0][1] = p0[1];
			p1[1][0] = p0[0] + step;
			p1[1][1] = p0[1];
			p1[2][0] = p0[0];
			p1[2][1] = p0[1] - step;
			p1[3][0] = p0[0];
			p1[3][1] = p0[1] + step;
			for(i = 0; i < 4; ++i){
				sum1[i] = sum_dist(p1[i], p, n);
			}
			mini = min_index(sum1, 4);
			if(sum1[mini] < sum0){
				p0[0] = p1[mini][0];
				p0[1] = p1[mini][1];
				sum0 = sum1[mini];
			}else{
				step = step * 0.5;
			}

			if(step < 0.1){
				break;
			}
		}

		printf("%.0f\n", sum0);
	}

	return 0;
}
