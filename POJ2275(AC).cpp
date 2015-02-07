#include <cstdio>
#include <vector>
using namespace std;

void rev(int a[], int ll, int rr)
{
	int i;
	int tmp;
	
	for (i = ll; i < ll + rr - i; ++i) {
		tmp = a[i];
		a[i] = a[ll + rr - i];
		a[ll + rr - i] = tmp;
	}
}

int main()
{
	int a[50];
	int n;
	int res;
	int i;
	int p;
	vector<int> seq;

	while (scanf("%d", &n) == 1 && n) {
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		res = 0;
		for (i = n; i >= 1; --i) {
			for (p = 1; p <= n; ++p) {
				if (a[p] == i) {
					break;
				}
			}
			if (p == i) {
				continue;
			}

			if (p == 1) {
				rev(a, 1, i);
				seq.push_back(i);
				++res;
			} else if (p != i) {
				rev(a, 1, p);
				seq.push_back(p);
				rev(a, 1, i);
				seq.push_back(i);
				res += 2;
			}
		}

		printf("%d", (int)seq.size());
		for (i = 0; i < seq.size(); ++i) {
			printf(" %d", seq[i]);
		}
		printf("\n");

		seq.clear();
	}

	return 0;
}