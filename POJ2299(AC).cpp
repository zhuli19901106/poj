#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[510000];
int t[510000];
int tc;
int n;
long long int inv;

void merge(int a[], int left, int mid, int right)
{
	int i, j;

	tc = left;
	i = left;
	j = mid + 1;
	while(true){
		if(i <= mid){
			if(j <= right){
				if(a[i] <= a[j]){
					t[tc++] = a[i++];
				}else{
					t[tc++] = a[j++];
					inv += mid - i + 1;
				}
			}else{
				t[tc++] = a[i++];
			}
		}else{
			if(j <= right){
				t[tc++] = a[j++];
			}else{
				break;
			}
		}
	}

	for(i = left; i <= right; ++i){
		a[i] = t[i];
	}
}

void msort(int a[], int left, int right)
{
	int mid;

	if(left < right){
		mid = (left + right) / 2;
		msort(a, left, mid);
		msort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

void MergeSort(int a[], int n)
{
	if(n < 2){
		return;
	}
	msort(a, 0, n - 1);
}

int main()
{
	int i;

	while(scanf("%d", &n) == 1 && n){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		inv = 0;
		MergeSort(a, n);

		printf("%lld\n", inv);
	}

	return 0;
}

