#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[2000];
double I, U, P;
bool bI, bU, bP;

int main()
{
	int t, ti;
	int i, len;
	double d;

	while(gets(s) != NULL){
		sscanf(s, "%d", &t);
		for(ti = 1; ti <= t; ++ti){
			gets(s);
			len = strlen(s);
			bI = bU = bP = false;
			for(i = 0; i < len - 1; ++i){
				if(s[i] == 'I' && s[i + 1] == '='){
					if(sscanf(s + i + 2, "%lf", &d) == 1){
						while(i < len && s[i] != 'A'){
							++i;
						}
						if(s[i - 1] == 'm'){
							I = d * 0.001;
						}else if(s[i - 1] == 'k'){
							I = d * 1000.0;
						}else if(s[i - 1] == 'M'){
							I = d * 1000000.0;
						}else{
							I = d;
						}
						bI = true;
					}
				}else if(s[i] == 'U' && s[i + 1] == '='){
					if(sscanf(s + i + 2, "%lf", &d) == 1){
						while(i < len && s[i] != 'V'){
							++i;
						}
						if(s[i - 1] == 'm'){
							U = d * 0.001;
						}else if(s[i - 1] == 'k'){
							U = d * 1000.0;
						}else if(s[i - 1] == 'M'){
							U = d * 1000000.0;
						}else{
							U = d;
						}
						bU = true;
					}
				}else if(s[i] == 'P' && s[i + 1] == '='){
					if(sscanf(s + i + 2, "%lf", &d) == 1){
						while(i < len && s[i] != 'W'){
							++i;
						}
						if(s[i - 1] == 'm'){
							P = d * 0.001;
						}else if(s[i - 1] == 'k'){
							P = d * 1000.0;
						}else if(s[i - 1] == 'M'){
							P = d * 1000000.0;
						}else{
							P = d;
						}
						bP = true;
					}
				}
			}

			printf("Problem #%d\n", ti);
			if(bI && bU){
				P = I * U;
				printf("P=%.2fW\n\n", P);
			}else if(bU && bP){
				I = P / U;
				printf("I=%.2fA\n\n", I);
			}else {
				U = P / I;
				printf("U=%.2fV\n\n", U);
			}
		}
	}

	return 0;
}
