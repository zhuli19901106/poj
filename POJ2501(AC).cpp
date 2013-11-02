#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[1000];
	int h;
	int m;
	int s;
	int ch;
	int cm;
	int cs;
	int qh;
	int qm;
	int qs;
	int speed;
	int cspeed;
	int seconds;
	double dist;
	double curdist;

	h = 0;
	m = 0;
	s = 0;
	speed = 0;
	dist = 0;
	while(1)
	{
		if(gets(buffer) == NULL)
		{
			break;
		}

		if(strlen(buffer) == 8)
		{
			sscanf(buffer, "%02d:%02d:%02d", &qh, &qm, &qs);

			seconds = (qh - h) * 3600 + (qm - m) * 60 + (qs - s);
			curdist = dist + seconds * speed / 3600.0;

			printf("%02d:%02d:%02d %0.2f km\n", qh, qm, qs, curdist);
		}
		else
		{
			sscanf(buffer, "%02d:%02d:%02d %d", &ch, &cm, &cs, &cspeed);

			seconds = (ch - h) * 3600 + (cm - m) * 60 + (cs - s);
			dist = dist + seconds * speed / 3600.0;

			h = ch;
			m = cm;
			s = cs;
			speed = cspeed;
		}
	}

	return 0;
}

