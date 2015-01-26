#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long int LL;
LL b[12] = {
	1, 10, 100, 1000, 10000, 
	100000, 1000000, 10000000, 100000000, 1000000000,
	10000000000, 100000000000
};

LL solve(LL n)
{
    LL left, m, sum;
	int i;

	sum = 1;
    for(i = 1; i < 12; ++i)
    {
        left = n / b[i] - 1;
        sum += left * b[i - 1];
        m = (n % b[i] - n % b[i - 1]) / b[i - 1];
		if(m > 0){
			sum += b[i - 1];
		}else if(m == 0){
			sum += n % b[i - 1] + 1;
		}
        if(n < b[i]){
			break;
		}
    }

    return sum;
}

int main()
{
    LL m, n;

    while(scanf("%lld%lld", &m, &n) == 2 && m >= 0){
		if(m == 0){
			printf("%lld\n", solve(n));
		}else{
			printf("%lld\n", solve(n) - solve(m - 1));
		}
	}
    return 0;
}
