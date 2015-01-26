#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

void swap(double &a, double &b)
{
	double t;

	t = a;
	a = b;
	b = t;
}

int main()
{
	double w1, h1, w2, h2, w3, h3;
	double r1, r2;

	while(scanf("%lf%lf%lf%lf", &w1, &h1, &w2, &h2) == 4){
		if(w1 == 0.0 && h1 == 0.0 && w2 == 0.0 && h2 == 0.0){
			break;
		}

		if(w1 < h1){
			swap(w1, h1);
		}
		if(w2 < h2){
			swap(w2, h2);
		}

		r1 = w1 / h1;
		r2 = w2 / h2;

		if(w2 >= w1 && h2 >= h1){
			printf("100%%\n");
			continue;
		}

		if(r1 >= r2){
			w3 = w2;
			h3 = w3 / r1;
		}else{
			h3 = h2;
			w3 = h3 * r1;
		}

		printf("%d%%\n", (int)(100.0 * w3 / w1));
	}

	return 0;
}
