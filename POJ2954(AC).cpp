#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int x[3];
int y[3];
double d[3];
int a, b, s;

inline int myabs(const int &a)
{
	return a > 0 ? a : -a;
}

inline int mymin(const int &a, const int &b)
{
	return a < b ? a : b;
}

int gcd(int a, int b)
{
	while(true){
		if(a >= b){
			if(a % b){
				a = a % b;
			}else{
				return b;
			}
		}else{
			if(b % a){
				b = b % a;
			}else{
				return a;
			}
		}
	}
}

int main()
{
	int dx, dy;

	while(scanf("%d%d%d%d%d%d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]) == 6 
		&& (x[0] || y[0] || x[1] || y[1] || x[2] || y[2])){
		s = myabs((x[0] - x[1]) * (y[0] - y[2]) - (x[0] - x[2]) * (y[0] - y[1])) / 2;
		b = 0;
		
		dx = myabs(x[0] - x[1]);
		dy = myabs(y[0] - y[1]);
		if(dx == 0){
			b += (dy - 1);
		}else if(dy == 0){
			b += (dx - 1);
		}else{
			b = gcd(dx, dy) - 1;
		}

		dx = myabs(x[1] - x[2]);
		dy = myabs(y[1] - y[2]);
		if(dx == 0){
			b += (dy - 1);
		}else if(dy == 0){
			b += (dx - 1);
		}else{
			b += gcd(dx, dy) - 1;
		}


		dx = myabs(x[2] - x[0]);
		dy = myabs(y[2] - y[0]);
		if(dx == 0){
			b += (dy - 1);
		}else if(dy == 0){
			b += (dx - 1);
		}else{
			b += gcd(dx, dy) - 1;
		}
		b += 3;

		printf("%d\n", int(s + 1 - b / 2 + 0.01));
	}

	return 0;
}
