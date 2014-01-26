#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef struct st_max {
	bool operator() (const int &x, const int &y)
	{
		return x > y;
	}
}st_max;

typedef struct st_min {
	bool operator() (const int &x, const int &y)
	{
		return x < y;
	}
}st_min;

int main()
{
	priority_queue<int, vector<int>, st_max> pmax;
	priority_queue<int, vector<int>, st_min> pmin;
	int n, n1, n2, n3;
	int tmp;
	int val;
	long long sum;
	int i;

	while (scanf("%d%d%d", &n1, &n2, &n) == 3) {
		if (!(n1 || n2 || n)) {
			break;
		}
		
		while (!pmax.empty()) {
			pmax.pop();
		}
		while (!pmin.empty()) {
			pmin.pop();
		}
		sum = 0;

		for (i = 0; i < n1; ++i) {
			scanf("%d", &tmp);
			sum += tmp;
			pmax.push(tmp);
		}

		for (i = 0; i < n2; ++i) {
			scanf("%d", &tmp);
			sum += tmp;
			if (tmp > pmax.top()) {
				val = pmax.top();
				pmax.pop();
				pmax.push(tmp);
				pmin.push(val);
			} else {
				pmin.push(tmp);
			}
		}

		n3 = n - n1 - n2;
		for (i = 0; i < n3; ++i) {
			scanf("%d", &tmp);
			sum += tmp;
			if (tmp > pmax.top()) {
				pmax.pop();
				pmax.push(tmp);
			} else if (tmp < pmin.top()) {
				pmin.pop();
				pmin.push(tmp);
			}
		}

		while (!pmax.empty()) {
			sum -= pmax.top();
			pmax.pop();
		}

		while (!pmin.empty()) {
			sum -= pmin.top();
			pmin.pop();
		}

		printf("%f\n", 1.0 * sum / n3);
	}

	return 0;
}