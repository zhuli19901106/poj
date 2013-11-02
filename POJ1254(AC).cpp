#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void getintersect(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y)
{
	if(a1 * b2 - a2 * b1 == 0)
	{
		return;
	}

	*x = (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
	*y = (c2 * a1 - c1 * a2) / (a2 * b1 - a1 * b2);
}

int main()
{
	const double pi = 3.141592653589793;
	double x1;
	double y1;
	double degree1;
	double x2;
	double y2;
	double degree2;
	double a1;
	double b1;
	double c1;
	double a2;
	double b2;
	double c2;
	double x;
	double y;
	int i;
	int n;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &x1, &y1, &degree1);
		scanf("%lf%lf%lf", &x2, &y2, &degree2);

		if(degree1 == 0 || degree1 == 180)
		{
			a1 = 1;
			b1 = 0;
			c1 = -x1;
		}
		else
		{
			a1 = tan((90 - degree1) / 180 * pi);
			b1 = -1;
			c1 = y1 - a1 * x1;
		}

		if(degree2 == 0 || degree2 == 180)
		{
			a2 = 1;
			b2 = 0;
			c2 = -x2;
		}
		else
		{
			a2 = tan((90 - degree2) / 180 * pi);
			b2 = -1;
			c2 = y2 - a2 * x2;
		}

		getintersect(a1, b1, c1, a2, b2, c2, &x, &y);
		printf("%0.4f %0.4f\n", x, y);
	}

	return 0;
}

