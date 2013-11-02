#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[2000];
const int MAXN = 505;
int a[MAXN], b[MAXN], p[10][MAXN];
int la, lb, lp[10];
int res[MAXN];
int lres;
char op;

int my_max3(const int &x, const int &y, const int &z)
{
	if(x > y){
		if(x > z){
			return x;
		}else{
			return z;
		}
	}else{
		if(y > z){
			return y;
		}else{
			return z;
		}
	}
}

int my_max2(const int &x, const int &y)
{
	return (x > y ? x : y);
}

void calc_len(const int arr[], int &len)
{
	int i;

	i = MAXN - 1;
	while(i >= 0 && arr[i] == 0){
		--i;
	}
	if(i < 0){
		len = 1;
	}else{
		len = i + 1;
	}
}

void my_add(int a[], int b[], int c[])
{
	int i;

	for(i = 0; i < MAXN; ++i){
		a[i] = b[i] + c[i];
	}

	for(i = 0; i < MAXN - 1; ++i){
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	a[MAXN - 1] %= 10;
}

void my_sub(int a[], int b[], int c[])
{
	int i;

	for(i = 0; i < MAXN; ++i){
		a[i] = b[i] - c[i];
	}
	for(i = 0; i < MAXN - 1; ++i){
		if(a[i] < 0){
			a[i] += 10;
			--a[i + 1];
		}
	}
	if(a[MAXN - 1] < 0){
		a[MAXN - 1] += 10;
	}
}

void my_multiply(int a[], int b[], int c[])
{
	int i, j;

	for(i = 0; i < MAXN; ++i){
		if(b[i] == 0){
			continue;
		}
		for(j = 0; i + j < MAXN; ++j){
			if(c[j] == 0){
				continue;
			}
			a[i + j] += b[i] * c[j];
		}
	}

	for(i = 0; i < MAXN - 1; ++i){
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	a[MAXN - 1] %= 10;
}

void fill_char(int n, char ch)
{
	int i;

	for(i = 0; i < n; ++i){
		putchar(ch);
	}
}

void print_digit(const int arr[], const int len)
{
	int i;

	i = len - 1;
	while(i >= 0){
		putchar('0' + arr[i]);
		--i;
	}
}

int main()
{
	int t, ti;
	int i, j, k;
	int len, maxlen;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			memset(a, 0, MAXN * sizeof(int));
			memset(b, 0, MAXN * sizeof(int));
			memset(res, 0, MAXN * sizeof(int));
			memset(p, 0, 10 * MAXN * sizeof(int));
			scanf("%s", s);
			len = strlen(s);
			for(j = 0; s[j]; ++j){
				if(!(s[j] >= '0' && s[j] <= '9')){
					break;
				}
			}
			k = j;
			op = s[k];
			
			i = 0;
			j = 0;
			while(i <= k - 1){
				a[j] = s[k - 1 - i] - '0';
				++i;
				++j;
			}

			i = k + 1; 
			j = 0;
			while(i <= len - 1){
				b[j] = s[k + len - i] - '0';
				++i;
				++j;
			}

			calc_len(a, la);
			calc_len(b, lb);
			if(op == '+' || op == '-'){
				if(op == '+'){
					my_add(res, a, b);
					calc_len(res, lres);
				}else{
					my_sub(res, a, b);
					calc_len(res, lres);
				}
				maxlen = my_max3(la, lb + 1, lres);
				fill_char(maxlen - la, ' ');
				print_digit(a, la);
				putchar('\n');
				fill_char(maxlen - lb - 1, ' ');
				putchar(op);
				print_digit(b, lb);
				putchar('\n');
				fill_char(maxlen - my_max2(lb + 1, lres), ' ');
				fill_char(my_max2(lb + 1, lres), '-');
				putchar('\n');
				fill_char(maxlen - lres, ' ');
				print_digit(res, lres);
				putchar('\n');
			}else if(op == '*'){
				my_multiply(res, a, b);
				calc_len(res, lres);
				maxlen = my_max3(la, lb + 1, lres);
				if(lb > 1){
					for(i = 0; i < 10; ++i){
						for(j = 0; j < MAXN; ++j){
							p[i][j] = a[j] * i;
						}
						for(j = 0; j < MAXN - 1; ++j){
							p[i][j + 1] += (p[i][j] / 10);
							p[i][j] %= 10;
						}
						p[i][MAXN - 1] %= 10;
						calc_len(p[i], lp[i]);
					}
					fill_char(maxlen - la, ' ');
					print_digit(a, la);
					putchar('\n');
					fill_char(maxlen - lb - 1, ' ');
					putchar(op);
					print_digit(b, lb);
					putchar('\n');
					fill_char(maxlen - my_max2(lb + 1, lp[b[0]]), ' ');
					fill_char(my_max2(lb + 1, lp[b[0]]), '-');
					putchar('\n');
					for(i = 0; i < lb; ++i){
						fill_char(maxlen - i - lp[b[i]], ' ');
						print_digit(p[b[i]], lp[b[i]]);
						putchar('\n');
					}
					fill_char(maxlen - my_max2(lres, lp[b[lb - 1]] + lb - 1), ' ');
					fill_char(my_max2(lres, lp[b[lb - 1]] + lb - 1), '-');
					putchar('\n');
					fill_char(maxlen - lres, ' ');
					print_digit(res, lres);
					putchar('\n');
				}else{
					fill_char(maxlen - la, ' ');
					print_digit(a, la);
					putchar('\n');
					fill_char(maxlen - lb - 1, ' ');
					putchar(op);
					print_digit(b, lb);
					putchar('\n');
					fill_char(maxlen - my_max2(lb + 1, lres), ' ');
					fill_char(my_max2(lb + 1, lres), '-');
					putchar('\n');
					fill_char(maxlen - lres, ' ');
					print_digit(res, lres);
					putchar('\n');
				}
			}else{
				//invalid input
			}

			printf("\n");
		}
	}

	return 0;
}

