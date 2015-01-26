#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct Point{
	int x;
	int y;
	bool b;
}Point;
vector<Point> v;
int res;
int cc;

bool comparator(const Point &a, const Point &b)
{
	if(a.x == b.x){
		return a.y < b.y;
	}else{
		return a.x < b.x;
	}
}

int main()
{
	Point p;
	int cx, cy, i, cc0;
	bool last_case;

	while(true){
		last_case = false;
		v.clear();
		while(scanf("%d%d", &p.x, &p.y) == 2){
			if(p.x == -1 && p.y == -1){
				last_case = true;
				break;
			}else if(p.x == 0 && p.y == 0){
				break;
			}else{
				p.b = false;
				v.push_back(p);
			}
		}
		if(last_case){
			break;
		}
		sort(v.begin(), v.end(), comparator);
		cc = v.size();
		res = 0;
		while(cc > 0){
			cx = 0;
			cy = 0;
			cc0 = cc;
			for(i = 0; i < (int)v.size(); ++i){
				if(v[i].b){
					continue;
				}
				if(v[i].x >= cx && v[i].y >= cy){
					v[i].b = true;
					cx = v[i].x;
					cy = v[i].y;
					--cc;
				}
			}

			if(cc < cc0){
				++res;
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
