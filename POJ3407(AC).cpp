#include <math.h>
#include <stdio.h>

double getlat(double latd, double latm, char latc)
{
	switch(latc)
	{
	case 'N':
		return 90 - (latd + latm / 60.0);
	case 'S':
		return 90 + (latd + latm / 60.0);
	}
}

double getlon(double lond, double lonm, char lonc)
{
	switch(lonc)
	{
	case 'E':
		return +(lond + lonm / 60.0);
	case 'W':
		return -(lond + lonm / 60.0);
	}
}

int main()
{
	char latc1;
	char lonc1;
	char latc2;
	char lonc2;
	double latd1;
	double latm1;
	double lond1;
	double lonm1;
	double latd2;
	double latm2;
	double lond2;
	double lonm2;
	double lat1;
	double lon1;
	double lat2;
	double lon2;
	double c;
	double dist;
	const double r = 6370;
	const double pi = 3.1415926;
	char buffer[1000];

	gets(buffer);
	sscanf(buffer, "%lf %lf %c %lf %lf %c", &latd1, &latm1, &latc1, &lond1, &lonm1, &lonc1);
	gets(buffer);
	sscanf(buffer, "%lf %lf %c %lf %lf %c", &latd2, &latm2, &latc2, &lond2, &lonm2, &lonc2);

	lat1 = getlat(latd1, latm1, latc1) * pi / 180;
	lat2 = getlat(latd2, latm2, latc2) * pi / 180;
	lon1 = getlon(lond1, lonm1, lonc1) * pi / 180;
	lon2 = getlon(lond2, lonm2, lonc2) * pi / 180;

	c = sin(lat1) * sin(lat2) * cos(lon1 - lon2) + cos(lat1) * cos(lat2);
	dist = r * acos(c);
	printf("%.3f\n", dist);

	return 0;
}

