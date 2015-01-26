#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long int LL;

const int MAXN = 1000005;
const int MOD = 11;
int b[MAXN];
char buf[MAXN];

int main()
{
	int m;
	int i;
	int ten, len;
	int CS;
	int ok;
	int dig0, f;
	
	CS = 0;
	while(scanf("%s", buf) == 1){
		if(strcmp(buf,"0") == 0){
			break;
		}else{
			++CS;
		}
		
		m = 0;
		ten = 1;
		len = strlen(buf);
		for(i = 0; i < len; ++i){
			m = m * 10 + buf[i] - '0';
			m %= MOD;
			ten = ten * 10 % MOD;
		}
		printf("%d. ", CS);
		
		ok = 0;
		dig0 = buf[len - 1] - '0';
		
		f = -1;
		for(i = 1; i < 11; ++i){
			if((i * ten + m) % MOD == 0){
				++ok;
				f = i;
				break;
			}
		}

		if(ok != 1){
			puts("IMPOSSIBLE");
		}else{
			for(i = 0; i < len; ++i){
				b[i] = buf[len - i - 1] - '0';
			}
			b[i++] = f;
			for(i--; i > 0; --i){
				b[i - 1] += b[i] % MOD * 10;
				b[i] /= MOD;
			}
			b[0] /= MOD;
			  
			for(i = len - 1; i >= 0; --i){
				putchar(b[i] + '0');
			}
			putchar('\n');
		}
	}
	return 0;
}
