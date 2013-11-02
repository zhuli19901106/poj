#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[50000];
int p[6000];
int pc;
int f[100];
int r[100];
int c[100];
int fc;

int n, m, m0;

int main()
{
	int i, j;

	memset(b, 0, 50000 * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i * i < 50000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j < 50000; ++j){
			b[i * j] = 1;
		}
	}

	pc = 0;
	for(i = 0; i < 50000; ++i){
		b[i] = !b[i];
		if(b[i]){
			p[pc++] = i;
		}
	}

	while(scanf("%d%d", &n, &m) == 2){
		if(m == 0){
			printf("%d does not divide %d!\n", m, n);
			continue;
		}

		if(n == 0){
			if(m == 1){
				printf("%d divides %d!\n", m, n);
				continue;
			}else{
				printf("%d does not divide %d!\n", m, n);
				continue;
			}
		}

		m0 = m;

		fc = 0;
		i = 0;
		while(true){
			if(m < p[i]){
				break;
			}else if(m % p[i] == 0){
				f[fc] = p[i];
				r[fc] = 0;
				while(m % p[i] == 0){
					m /= p[i];
					++r[fc];
				}
				++fc;
				++i;
			}else{
				++i;
			}

			if(i == pc){
				break;
			}
		}

		if(m > 1){
			f[fc] = m;
			r[fc] = 1;
			++fc;
			m = 1;
		}

		m = m0;

		for(i = 0; i < fc; ++i){
			m0 = 1;
			c[i] = 0;
			while(m0 <= n / f[i]){
				m0 *= f[i];
				c[i] += n / m0;
			}
		}

		for(i = 0; i < fc; ++i){
			if(c[i] < r[i]){
				break;
			}
		}

		if(i == fc){
			printf("%d divides %d!\n", m, n);
		}else{
			printf("%d does not divide %d!\n", m, n);
		}
	}

	return 0;
}

