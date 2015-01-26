#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int s, x, y, dx, dy;
	int cx, cy, rx, ry;
	int c;
	
	while(true){
		if(scanf("%d%d%d%d%d", &s, &x, &y, &dx, &dy) != 5){
			break;
		}else if(!(s || x || y || dx || dy)){
			break;
		}
		c = 0;
		while(true){
			if(c > 2000){
				printf("The flea cannot escape from black squares.\n");
				break;
			}
			cx = x / s;
			cy = y / s;
			rx = x % s;
			ry = y % s;
			if(((cx + cy) % 2 == 1) && (rx != 0) && (ry != 0)){
				printf("After %d jumps the flea lands at (%d, %d).\n", c, x, y);
				break;
			}else{
				x += dx;
				y += dy;
				++c;
			}
		}
	}
	
	return 0;
}
