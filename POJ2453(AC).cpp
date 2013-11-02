#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool comparator(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int n;
	int i;
	int a[100];
	int ac;

	while(scanf("%d", &n) == 1 && n){
		ac = 0;
		memset(a, 0, 100 * sizeof(int));
		while(true){
			a[ac++] = n % 2;
			n /= 2;
			if(n == 0){
				break;
			}
		}
		i = 1;
		while(!(a[i] == 0 && a[i - 1] == 1)){
			++i;
		}
		n = a[i];
		a[i] = a[i - 1];
		a[i - 1] = n;
		sort(a, a + i, comparator);

		n = 0;
		ac = 99;
		while(ac >= 0 && !a[ac]){
			--ac;
		}
		++ac;
		for(i = ac - 1; i >= 0; --i){
			n *= 2;
			n += a[i];
		}
		printf("%d\n", n);
	}

	return 0;
}

