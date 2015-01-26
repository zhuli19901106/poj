#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

typedef long long int LL;
priority_queue<int, vector<int>, less<int>> pmin;//root is max
priority_queue<int, vector<int>, greater<int>> pmax;//root is min
LL sum;
int n1, n2, n;

int main()
{
	int i;
	int a, x, y;
	int f[30];

	while(scanf("%d%d%d", &n1, &n2, &n) == 3 && (n1 || n2 || n)){
		sum = 0;
		for(i = 0; i < n1 + n2; ++i){
			scanf("%d", &f[i]);
			sum += f[i];
		}
		sort(f, f + n1 + n2);
		for(i = 0; i < n2; ++i){
			pmin.push(f[i]);
		}
		for(i = n2; i < n1 + n2; ++i){
			pmax.push(f[i]);
		}
		f[0] = n - n1 - n2;
		for(i = 0; i < f[0]; ++i){
			scanf("%d", &a);
			if(a > pmax.top()){
				pmax.pop();
				pmax.push(a);
			}else if(a < pmin.top()){
				pmin.pop();
				pmin.push(a);
			}
			sum += a;
		}
		while(!pmax.empty()){
			sum -= pmax.top();
			pmax.pop();
		}
		while(!pmin.empty()){
			sum -= pmin.top();
			pmin.pop();
		}
		printf("%f\n", 1.0 * sum / (n - n1 - n2));
	}

	return 0;
}
