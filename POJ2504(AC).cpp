#include <math.h>
#include <stdio.h>

void getabc(double x1, double y1, double x2, double y2, double *a, double *b, double *c)
{
	if(x1 == x2 && y1 != y2)
	{
		*a = 1;
		*b = 0;
		*c = -x1;
		return;
	}

	*a = (y2 - y1) / (x2 - x1);
	*b = -1;
	*c = (x1 * y2 - x2 * y1) / (x1 - x2);
}

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
	int i;
	int n;
	double vx[60];
	double vy[60];
	double x[3];
	double y[3];
	double ta;
	double tb;
	double tc;
	double a1;
	double b1;
	double c1;
	double a2;
	double b2;
	double c2;
	double cx;
	double cy;
	double mid01x;
	double mid01y;
	double mid12x;
	double mid12y;
	double radius;
	double maxx;
	double maxy;
	double minx;
	double miny;
	double area;
	double startangle;
	const double pi = 3.1415926535897932384626433832795;
	int counter;

	counter = 0;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
		{
			break;
		}

		for(i = 0; i < 3; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
		}

		mid01x = (x[0] + x[1]) / 2;
		mid01y = (y[0] + y[1]) / 2;
		getabc(x[0], y[0], x[1], y[1], &ta, &tb, &tc);
		a1 = -tb;
		b1 = ta;
		c1 = -(a1 * mid01x + b1 * mid01y);

		mid12x = (x[1] + x[2]) / 2;
		mid12y = (y[1] + y[2]) / 2;
		getabc(x[1], y[1], x[2], y[2], &ta, &tb, &tc);
		a2 = -tb;
		b2 = ta;
		c2 = -(a2 * mid12x + b2 * mid12y);

		getintersect(a1, b1, c1, a2, b2, c2, &cx, &cy);

		radius = sqrt((cx - x[0]) * (cx - x[0]) + (cy - y[0]) * (cy - y[0]));
		startangle = acos((x[0] - cx) / radius);
		for(i = 0; i < n; i++)
		{
			vx[i] = cx + radius * cos((i * 360.0 / n) / 180.0 * pi + startangle);
			vy[i] = cy + radius * sin((i * 360.0 / n) / 180.0 * pi + startangle);
		}

		maxx = minx = vx[0];
		maxy = miny = vy[0];
		for(i = 1; i < n; i++)
		{
			if(vx[i] > maxx)
			{
				maxx = vx[i];
			}
			if(vx[i] < minx)
			{
				minx = vx[i];
			}
			if(vy[i] > maxy)
			{
				maxy = vy[i];
			}
			if(vy[i] < miny)
			{
				miny = vy[i];
			}
		}

		area = (maxx - minx) * (maxy - miny);
		printf("Polygon %d: %0.3f\n", counter + 1, area);
		counter++;
	}

	return 0;
}

