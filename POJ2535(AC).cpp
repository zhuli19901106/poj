#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
	int degree;
	int index;
}st;
st a[100];
int hardest[100];
int simplest[100];
int n, p;

int comp(const void *a, const void *b)
{
	const st *sa, *sb;
	
	sa = (const st *)a;
	sb = (const st *)b;
	
	return sa->degree - sb->degree;
}

int main()
{
	int i, j;
	int min_value, max_value;
	int found_count;
	
	while(true){
		if(scanf("%d%d", &n, &p) != 2){
			break;
		}
		memset(simplest, 0, 100 * sizeof(int));
		memset(hardest, 0, 100 * sizeof(int));
		for(i = 0; i < n; ++i){
			memset(a, 0, 100 * sizeof(st));
			for(j = 0; j < p; ++j){
				scanf("%d", &a[j].degree);
				a[j].index = j;
			}
			qsort(a, p, sizeof(st), comp);
			min_value = a[0].degree;
			max_value = a[p - 1].degree;
			
			j = 0;
			while(a[j].degree == min_value){
				++simplest[a[j].index];
				++j;
			}
			
			j = p - 1;
			while(a[j].degree == max_value){
				hardest[a[j].index] = true;
				--j;
			}
		}
		
		found_count = 0;
		for(i = 0; i < p; ++i){
			if(simplest[i] >= n / 2 + 1 && !hardest[i]){
				if(found_count == 0){
					printf("%d", i + 1);
				}else{
					printf(" %d", i + 1);
				}
				++found_count;
			}
		}
		if(found_count == 0){
			printf("0");
		}
		printf("\n");
	}
	
	return 0;
}

