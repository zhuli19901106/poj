#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

struct comp
{
	bool operator()(const double &a, const double &b)
	{
		return a < b;
	}
};

priority_queue<double, vector<double>, comp> pq;
int n;

int main()
{
	double a, b;
	int i;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		
		while(!pq.empty()){
			pq.pop();
		}
		
		for(i = 0; i < n; ++i){
			scanf("%lf", &a);
			pq.push(a);
		}
		
		for(i = 0; i < n - 1; ++i){
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			a = 2 * sqrt(a * b);
			pq.push(a);
		}
		
		a = pq.top();
		pq.pop();
		printf("%.3f\n", a);
	}
	
	return 0;
}
