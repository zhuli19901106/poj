#include <math.h>
#include <stdio.h>

int main()
{
	double D;
	double R;
	double d;
	double r;
	double V;
	double Vsum;
	double Vtotal;
	const double pi = 3.1415926535898;

	while(1)
	{
		if(scanf("%lf%lf", &D, &V) != 2)
		{
			break;
		}
		if(D == 0 && V == 0)
		{
			break;
		}

		R = D / 2.0;
		Vtotal = pi * R * R * D;
		Vsum = Vtotal - V;
		/*
		Vsum = 2 * pi * r * r * r +  2.0 * (pi * R * R * R - pi * r * r * r) / 3.0;
		Vsum = 2 / 3 pi * R * R * R + 4 / 3 * pi * r * r * r;
		*/
		r = pow((Vsum * 3 - 2 * pi * R * R * R) / 4.0 / pi, 1.0 / 3.0);
		d = r * 2.0;

		printf("%0.3f\n", d);
	}

	return 0;
}

