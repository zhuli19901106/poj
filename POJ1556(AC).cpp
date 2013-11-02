#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<double> vy[20];
vector<double> vy0[20];
vector<double> vx;
int vc;
double mind;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool comparator(const double &a, const double &b)
{
	return fabs(a - 5.0) < fabs(b - 5.0);
}

void dfs(double cx, double cy, int index, double d)
{
	int i, j, p;
	bool suc;
	double y;
	double d1, d2;

	if(d >= mind){
		return;
	}

	if(cx == 10.0 && cy == 5.0){
		if(d < mind){
			mind = d;
		}
		return;
	}else if(index >= vc){
		dfs(10.0, 5.0, index, d + dist(cx, cy, 10.0, 5.0));
	}else{
		suc = true;
		for(p = index; p <= vc - 1; ++p){
			d1 = vx[p] - cx;
			d2 = 10.0 - vx[p];
			y = (cy * d2 + 5.0 * d1) / (d1 + d2);
			if(
				(y < vy0[p][0]) ||
				(y > vy0[p][1] && y < vy0[p][2]) ||
				(y > vy0[p][3])
			){
				suc = false;
				break;
			}
		}
		if(suc){
			dfs(10.0, 5.0, vc, d + dist(cx, cy, 10.0, 5.0));
			return;
		}

		for(i = vc - 1; i >= index; --i){
			for(j = 0; j < 4; ++j){
				suc = true;
				for(p = index; p < i; ++p){
					d1 = vx[p] - cx;
					d2 = vx[i] - vx[p];
					y = (cy * d2 + vy[i][j] * d1) / (d1 + d2);
					if(
						(y < vy0[p][0]) ||
						(y > vy0[p][1] && y < vy0[p][2]) ||
						(y > vy0[p][3])
					){
						suc = false;
						break;
					}
				}

				if(suc){
					dfs(vx[i], vy[i][j], i + 1, d + dist(cx, cy, vx[i], vy[i][j]));
				}
			}
		}
	}
}

int main()
{
	int i, j;
	double tmp;

	while(scanf("%d", &vc) == 1 && vc != -1){
		vx.clear();
		for(i = 0; i < vc; ++i){
			vy[i].clear();
			vy0[i].clear();
			scanf("%lf", &tmp);
			vx.push_back(tmp);
			for(j = 0; j < 4; ++j){
				scanf("%lf", &tmp);
				vy[i].push_back(tmp);
				vy0[i].push_back(tmp);
			}
			sort(vy[i].begin(), vy[i].end());
		}
		mind = 1e99;
		dfs(0.0, 5.0, 0, 0.0);
		printf("%.2f\n", mind);
	}

	return 0;
}

