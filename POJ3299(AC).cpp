#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[100];
double t, d, h, e, hd;
const double INF = 9999999;
const double e0 = 2.718281828;

int main()
{
	double n;

	while(scanf("%s", s) == 1 && strcmp(s, "E")){
		t = d = h = INF;
		scanf("%lf", &n);
		if(strcmp(s, "T") == 0){
			t = n;
		}else if(strcmp(s , "D") == 0){
			d = n;
		}else if(strcmp(s, "H") == 0){
			h = n;
		}

		scanf("%s%lf", s, &n);
		if(strcmp(s, "T") == 0){
			t = n;
		}else if(strcmp(s , "D") == 0){
			d = n;
		}else if(strcmp(s, "H") == 0){
			h = n;
		}

		if(t == INF){
			e = 6.11 * pow(e0, 5417.7530 * ((1.0 / 273.16) - (1.0 / (d + 273.16))));
			hd = (0.5555) * (e - 10.0);
			t = h - hd;
		}else if(d == INF){
			hd = h - t;
			e = hd / 0.5555 + 10.0;
			d = 1.0 / (1.0 / 273.16 - log(e / 6.11) / log(e0) / 5417.7530) - 273.16;
		}else if(h == INF){
			e = 6.11 * pow(e0, 5417.7530 * ((1.0 / 273.16) - (1.0 / (d + 273.16))));
			hd = (0.5555) * (e - 10.0);
			h = t + hd;
		}

		printf("T %.1f D %.1f H %.1f\n", t, d, h);
	}

	return 0;
}

