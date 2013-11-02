#include <math.h>
#include <stdio.h>

typedef struct Point{
	double x;
	double y;
}POINT;

double dist(POINT p, POINT q)
{
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

void cocircle(POINT p1, POINT p2, POINT p3, POINT *q, double *r)
{
	double x12;
	double y12;
	double x13;
	double y13;
	double z2;
	double z3;
	double d;

	x12 = p2.x - p1.x;
	y12 = p2.y - p1.y;
	x13 = p3.x - p1.x;
	y13 = p3.y - p1.y;
	z2 = x12 * (p1.x + p2.x) + y12 * (p1.y + p2.y);
	z3 = x13 * (p1.x + p3.x) + y13 * (p1.y + p3.y);
	d = 2.0 * (x12 * (p3.y - p2.y) - y12 * (p3.x - p2.x));

	q->x = (y13 * z2 - y12 * z3) / d;
	q->y = (x12 * z3 - x13 * z2) / d;
	*r = dist(p1, *q);
}

int main()
{
	POINT p[3];
	POINT center;
	double radius;
	const double pi = 3.141592653589793;

	while(scanf("%lf%lf%lf%lf%lf%lf", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y) == 6)
	{

		cocircle(p[0], p[1], p[2], &center, &radius);
		printf("%0.2f\n", 2 * pi * radius);
	}

	return 0;
}

