#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[2000];
int n;
int inv;

int main()
{
	int i, j;
	int cc, cci;

	scanf("%d", &cc);
	for(cci = 1; cci <= cc; ++cci){
		scanf("%d", &n);
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}

		inv = 0;
		for(i = 0; i < n; ++i){
			for(j = i + 1; j < n; ++j){
				if(a[i] > a[j]){
					++inv;
				}
			}
		}

		printf("Scenario #%d:\n%d\n\n", cci, inv);
	}

	return 0;
}

