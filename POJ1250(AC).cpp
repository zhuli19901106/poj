#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i;
	int j;
	int n;
	int unserved;
	char line[50];
	char str[1000];
	int letter[26];
	
	while(true){
		for(i = 0; i < 26; i++){
			letter[i] = 0;
		}
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		
		scanf("%s", str);
		
		for(i = 0; i < n; i++){
			line[i] = ' ';
		}
		
		i = 0;
		unserved = 0;
		while(str[i] != 0){
			for(j = 0; j < n; j++){
				if(str[i] == line[j]){
					break;
				}
			}
			if(j == n){
				for(j = 0; j < n; j++){
					if(line[j] == ' '){
						break;
					}
				}
				if(j == n){
					if(letter[str[i] - 'A']){
						letter[str[i] - 'A'] = 0;
					}else{
						letter[str[i] - 'A'] = 1;
						unserved++;
					}
				}else{
					line[j] = str[i];
				}
			}else{
				line[j] = ' ';
			}
			i++;
		}
		
		if(0 == unserved){
			printf("All customers tanned successfully.\n");
		}else{
			printf("%d customer(s) walked away.\n", unserved);
		}
	}
	
	return 0;
}
