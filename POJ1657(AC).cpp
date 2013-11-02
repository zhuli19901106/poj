#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int myabs(int a)
{
	return (a >= 0 ? a : -a);
}

int mymax(int a, int b)
{
	return (a >= b ? a : b);
}

int main()
{
	int x1, y1;
	int x2, y2;
	int dx, dy;
	char s[10];
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%s", s);
			x1 = s[0] - 'a';
			y1 = s[1] - '1';
			scanf("%s", s);
			x2 = s[0] - 'a';
			y2 = s[1] - '1';

			dx = myabs(x1 - x2);
			dy = myabs(y1 - y2);

			if(dx == 0 && dy == 0){
				printf("0 0 0 0\n");
				continue;
			}

			if(dx == 0){
				printf("%d", dy);
			}else if(dy == 0){
				printf("%d", dx);
			}else if(dx == dy){
				printf("%d", dx);
			}else{
				printf("%d", mymax(dx, dy));
			}

			if(dx == 0 || dy == 0 || dx == dy){
				printf(" 1");
			}else{
				printf(" 2");
			}
			
			if(dx == 0 || dy == 0){
				printf(" 1");
			}else{
				printf(" 2");
			}

			if(dx == dy){
				printf(" 1\n");
			}else if((dx + dy) % 2 == 0){
				printf(" 2\n");
			}else{
				printf(" Inf\n");
			}
		}
	}

	return 0;
}

