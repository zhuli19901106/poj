#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[21];
int f1[21];
int f2[21];
int min_res;
const int INF = 1000000000;

const int &mymin(const int &x, const int &y)
{
	return x < y ? x : y;
}

int solve(int arr[])
{
	int res;
	int i;

	res = 0;
	for(i =	1; i <= 18; ++i){
		if(arr[i]){
			arr[i] = !arr[i];
			arr[i + 1] = !arr[i + 1];
			arr[i + 2] = !arr[i + 2];
			++res;
		}
	}

	if(arr[19] == 1 && arr[20] == 1){
		++res;
	}else if(arr[19] == 0 && arr[20] == 0){
		;
	}else{
		res = INF;
	}

	return res;
}

int main()
{
	int i;

	for(i = 1; i <= 20; ++i){
		scanf("%d", &a[i]);
	}

	for(i = 1; i <= 20; ++i){
		f1[i] = f2[i] = a[i];
	}
	f2[1] = !f2[1];
	f2[2] = !f2[2];

	min_res = mymin(solve(f1), solve(f2) + 1);

	printf("%d\n", min_res);

	return 0;
}

