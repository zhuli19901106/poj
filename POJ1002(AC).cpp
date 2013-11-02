#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX 10000000
int a[100000];

void normalize(char si[], char sj[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(si[i] != 0){
		if(si[i] != '-'){
			sj[j] = si[i];
			i++;
			j++;
		}else{
			i++;
		}
	}
	sj[j] = 0;
}

int getdigit(char c)
{
	if(c >= '0' && c <= '9'){
		return c - '0';
	}else if(c >= 'a' && c <= 'z'){
		return getdigit(c - 'a' + 'A');
	}else if(c >= 'A' && c <= 'Z'){
		switch(c){
		case 'A':
		case 'B':
		case 'C':
			return 2;
		case 'D':
		case 'E':
		case 'F':
			return 3;
		case 'G':
		case 'H':
		case 'I':
			return 4;
		case 'J':
		case 'K':
		case 'L':
			return 5;
		case 'M':
		case 'N':
		case 'O':
			return 6;
		case 'P':
		//case 'Q':
		case 'R':
		case 'S':
			return 7;
		case 'T':
		case 'U':
		case 'V':
			return 8;
		case 'W':
		case 'X':
		case 'Y':
			return 9;
		//case 'Z':
		default:
				return -1;
		}
	}else{
		return -1;
	}
}

int getphone(char s[])
{
	int i;
	int d;
	int len;
	int result;

	result = 0;
	len = strlen(s);
	for(i = 0; i < len; i++){
		d = getdigit(s[i]);
		if(d == -1){
			printf("ERROR\n");
		}
		result = result * 10 + d;
	}

	return result;
}

int comparator(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

int main()
{
	int n;
	int i;
	int j;
	char si[1000];
	char sj[1000];
	int phone_num;
	bool duplicate;

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}

		duplicate = false;
		for(i = 0; i < n; i++){
			scanf("%s", si);
			normalize(si, sj);
			phone_num = getphone(sj);
			a[i] = phone_num;
		}
		qsort(a, n, sizeof(int), comparator);

		i = 0;
		while(true){
			if(i >= n){
				break;
			}

			j = i + 1;
			while(true){
				if(j >= n || a[j] != a[i]){
					break;
				}else{
					j++;
				}
			}
			if(j - i >= 2){
				duplicate = true;
				printf("%03d-%04d %d\n", a[i] / 10000, a[i] % 10000, j - i);
			}

			i = j;
		}

		if(duplicate == false)
		{
			printf("No duplicates.\n");
		}
	}
	
	return 0;
}

