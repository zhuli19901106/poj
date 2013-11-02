#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;

void swap(LL &a, LL &b)
{
	LL t;
	
	t = a;
	a = b;
	b = t;
}

LL combination(LL w, LL h)
{
	LL sum;
	LL deno;
	LL i;
	
	if(w < h){
		return 0;
	}
	if(h > w / 2){
		return combination(w, w - h);
	}
	
	sum = 1;
	deno = 1;
	for(i = w; i > w - h; --i){
		sum = sum * i;
		if(sum % deno == 0){
			sum = sum / deno;
			deno = 1;
		}
		if(sum % (w + 1 - i) == 0){
			sum = sum / (w + 1 - i);
		}else{
			deno = deno * (w + 1 - i);
		}
	}
	if(sum % deno == 0){
		sum = sum / deno;
		deno = 1;
	}
	
	return sum;
}

int main()
{
	LL w, h;
	
	while(scanf("%lld%lld", &w, &h) == 2 && !(w == 0 && h == 0)){
		if(w < h){
			swap(w, h);
		}
		printf("%lld\n", combination(w + h, h));
	}
	
	return 0;
}

