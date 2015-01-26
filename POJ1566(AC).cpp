#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool is_syllable(const char &ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

int main()
{
	char s[1000];
	int i;
	int syllable_count;
	int line_no;
	
	while(true){
		if(gets(s) == NULL){
			break;
		}else if(strcmp(s, "e/o/i") == 0){
			break;
		}
		
		i = 0;
		line_no = 1;
		syllable_count = 0;
		while(true){
			if(s[i] == 0){
				if(syllable_count != 5){
					printf("3\n");
				}else{
					printf("Y\n");
				}
				break;
			}else if(s[i] == '/'){
				if(line_no == 1){
					if(syllable_count != 5){
						printf("1\n");
						break;
					}else{
						++line_no;
						syllable_count = 0;
					}
				}else if(line_no == 2){
					if(syllable_count != 7){
						printf("2\n");
						break;
					}else{
						++line_no;
						syllable_count = 0;
					}
				}else{
					//impossible
				}
			}else if(is_syllable(s[i])){
				++syllable_count;
				while(is_syllable(s[++i]))
					;
				--i;
			}else{
				//do nothing
			}
			++i;
		}
	}
	
	return 0;
}
