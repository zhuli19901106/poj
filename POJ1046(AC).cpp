#include <stdio.h>

typedef struct Point{
	int x;
	int y;
	int z;
}Point;

int GetDist(Point a, Point b)
{
	return ((a.x - b.x) * (a.x - b.x) +  (a.y - b.y) * (a.y - b.y) +  (a.z - b.z) * (a.z - b.z));
}

int main()
{
	Point p[16];
	Point p1;
	int minindex;
	int dist;
	int mindist;
	int i;

	for(i = 0; i < 16; i++)
	{
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
	}

	while(1)
	{
		scanf("%d%d%d", &p1.x, &p1.y, &p1.z);

		if(p1.x == -1 && p1.y == -1 && p1.z == -1)
		{
			break;
		}
		minindex = 0;
		mindist = GetDist(p[0], p1);
		for(i = 1; i < 16; i++)
		{
			dist = GetDist(p[i], p1);
			if(dist < mindist)
			{
				minindex = i;
				mindist = dist;
			}
		}

		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", p1.x, p1.y, p1.z, p[minindex].x, p[minindex].y, p[minindex].z);
	}

	return 0;
}

