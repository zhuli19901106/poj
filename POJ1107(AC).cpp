#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s1[1000], s2[1000];
int k1, k2, k3;
char c1[1000], c2[1000], c3[1000];
int p1[1000], p2[1000], p3[1000];
int cc1, cc2, cc3;

int main()
{
	int i;

	while(scanf("%d%d%d", &k1, &k2, &k3) == 3 && (k1 || k2 || k3)){
		scanf("%s", s1);
		memset(s2, 0, 300 * sizeof(char));
		cc1 = cc2 = cc3 = 0;
		for(i = 0; s1[i]; ++i){
			if(s1[i] >= 'a' && s1[i] <= 'i'){
				c1[cc1] = s1[i];
				p1[cc1] = i;
				++cc1;
			}else if(s1[i] >= 'j' && s1[i] <= 'r'){
				c2[cc2] = s1[i];
				p2[cc2] = i;
				++cc2;
			}else if(s1[i] == '_' || s1[i] >= 's' && s1[i] <= 'z'){
				c3[cc3] = s1[i];
				p3[cc3] = i;
				++cc3;
			}
		}

		for(i = 0; i < cc1; ++i){
			s2[p1[(i + k1) % cc1]] = c1[i];
		}
		for(i = 0; i < cc2; ++i){
			s2[p2[(i + k2) % cc2]] = c2[i];
		}
		for(i = 0; i < cc3; ++i){
			s2[p3[(i + k3) % cc3]] = c3[i];
		}

		printf("%s\n", s2);
	}

	return 0;
}

