#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int sum[5000];
	int sc;
	int i;
	int n;
	int l, r;
	
	sum[0] = 0;
	sc = 1;
	while(true){
		sum[sc] = sum[sc - 1] + sc;
		if(sum[sc] > 10000000){
			break;
		}else{
			++sc;
		}
	}
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		
		i = 1;
		while(n > sum[i]){
			++i;
		}
		//注意奇偶性问题
		if(i % 2){
			l = 1 + (sum[i] - n);
			r = i - (sum[i] - n);
		}else{
			l = i - (sum[i] - n);
			r = 1 + (sum[i] - n);
		}
		printf("TERM %d IS %d/%d\n", n, l, r);
	}
	
	return 0;
}
