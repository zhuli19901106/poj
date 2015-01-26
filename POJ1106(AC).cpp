#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct Point{
	double x;
	double y;
}Point;
vector<Point> v;
Point tr;
double r;
int maxc;

double cross(const Point &a, const Point &b, const Point &c)
{
	return (a.x - c.x) * (b.y-c.y) - (b.x - c.x) * (a.y - c.y);
}

int main()
{
	int i, j, n;
	int c;
	Point p;

	while(scanf("%lf%lf%lf", &tr.x, &tr.y, &r) == 3 && r >= 0){
		scanf("%d", &n);
		v.clear();
		for(i = 0; i < n; ++i){
			scanf("%lf%lf", &p.x, &p.y);
			if((p.x - tr.x) * (p.x - tr.x) + (p.y - tr.y) * (p.y - tr.y) <= r * r){
				v.push_back(p);
			}
		}
		n = v.size();
		maxc = 0;
		for(i = 0; i < n; ++i){
			c = 0;
			for(j = 0; j < n; ++j){
				if(cross(v[i], v[j], tr) <= 0){
					++c;
				}
			}
			if(2 * c < n){
				c = n - c;
			}
			if(c > maxc){
				maxc = c;
			}
		}

		printf("%d\n", maxc);
	}

	return 0;
}
