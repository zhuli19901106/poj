#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int comp(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

int v[10];
int a[1000];
int c;

int main()
{
	int case_count, case_no;
	int sum;
	int max_n;
	int i, j;
	int n;
	queue<int> q;
	int qc, nqc;
	
	while(true){
		if(scanf("%d", &case_count) != 1){
			break;
		}
		for(case_no = 0; case_no < case_count; ++case_no){
			for(i = 0; i < 6; ++i){
				scanf("%d", &v[i]);
			}
			qsort(v, 6, sizeof(int), comp);
			for(i = 0; i < 1000; ++i){
				a[i] = 0;
			}

			while(!q.empty()){
				q.pop();
			}

			qc = 0;
			for(i = 0; i < 6; ++i){
				if(a[v[i]] == 0){
					a[v[i]] = 1;
				}
				q.push(v[i]);
				++qc;
			}
			
			c = 2;
			while(!q.empty()){
				nqc = 0;
				for(i = 0; i < qc; ++i){
					n = q.front();
					q.pop();
					for(j = 0; j < 6; ++j){
						if(n + v[j] > 0 && n + v[j] < 1000 && a[n + v[j]] == 0){
							a[n + v[j]] = c;
							q.push(n + v[j]);
							++nqc;
						}
						if(n - v[j] > 0 && n - v[j] < 1000 && a[n - v[j]] == 0){
							a[n - v[j]] = c;
							q.push(n - v[j]);
							++nqc;
						}
					}
				}
				qc = nqc;
				++c;
			}

			sum = 0;
			max_n = -1;
			for(i = 1; i <= 100; ++i){
				sum = sum + a[i];
				if(a[i] > max_n){
					max_n = a[i];
				}
			}
			
			printf("%.2f %d\n", 1.0 * sum / 100, max_n);
		}
	}
	
	return 0;
}
