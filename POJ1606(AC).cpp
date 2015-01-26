#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

void swap(int *a,int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void swap(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int ca;
	int cb;
	int n;
	char na;
	char nb;

	int a;
	int b;

	int success;

	while(true){
		if(scanf("%d%d%d", &ca, &cb, &n) != 3){
			break;
		}

		na = 'A';
		nb = 'B';

		if(ca > cb){
			swap(&ca, &cb);
			swap(&na, &nb);
		}

		a = 0;
		b = 0;
		success = 0;
		while(success == 0){
			//Fill b
			b = cb;
			printf("fill %c\n", nb);
			if(a == n || b == n){
				success = 1;
				break;
			}

			while(success == 0 && b >= ca){
				//Pour b into a
				b = b - (ca - a);
				a = ca;
				printf("pour %c %c\n", nb, na);
				if(a == n || b == n){
					success = 1;
					break;
				}

				//Empty a
				a = 0;
				printf("empty %c\n", na);
				if(a == n || b == n){
					success = 1;
					break;
				}
			}

			if(success == 1){
				break;
			}

			//Pour b into a
			a = b;
			b = 0;
			printf("pour %c %c\n", nb, na);
			if(a == n || b == n){
				success = 1;
				break;
			}
		}
		printf("success\n");
	}

	return 0;
}
