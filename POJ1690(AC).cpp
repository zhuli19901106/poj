#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

string process(string s)
{
	string res;
	string ps, p1, p2;
	int i, j;
	int flag;
	int lit_count;

	i = 0;
	flag = 1;
	while(true){
		if(i == s.size()){
			break;
		}
		if(s[i] == '-'){
			flag = -1;
		}else if(s[i] == '+'){
			flag = 1;
		}else if(s[i] == '('){
			//entering a pair of brackets
			j = i + 1;
			lit_count = 0;
			while(!st.empty()){
				st.pop();
			}
			st.push('(');
			while(true){
				if(s[j] == '('){
					st.push('(');
				}else if(s[j] == ')'){
					st.pop();
				}else if(s[j] >= 'A' && s[j] <= 'Z'){
					++lit_count;
				}

				if(st.empty()){
					break;
				}else{
					++j;
				}
			}
			ps = s.substr(i + 1, j - i - 1);
			res = process(ps);
			if(i - 1 >= 0){
				p1 = s.substr(0, i);
			}else{
				p1 = "";
			}
			if(j + 1 < (int)s.size()){
				p2 = s.substr(j + 1, s.size() - j - 1);
			}else{
				p2 = "";
			}
			if(flag == 1 || lit_count < 2){
				s = p1 + res + p2;
				i = p1.size() + res.size() - 1;
			}else if(flag == -1){
				s = p1 + "(" + res + ")" + p2;
				i = p1.size() + res.size() + 1;
			}
		}
		++i;
	}

	return s;
}

int main()
{
	char str[1000];
	char s1[1000];
	string s;
	int n, ni, i, j;
	
	while(true){
		if(gets(str) == NULL){
			break;
		}
		sscanf(str, "%d", &n);
		for(ni = 0; ni < n; ++ni){
			gets(str);
			while(!st.empty()){
				st.pop();
			}
			s = string(str);
			sprintf(str, "%s", s.data());
			j = 0;
			for(i = 0; str[i] != 0; ++i){
				if(str[i] != ' ' && str[i] != '\t'){
					s1[j++] = str[i];
				}
			}
			s1[j] = 0;
			s = string(s1);
			s = process(s);
			printf("%s\n", s.data());
		}
	}
	
	return 0;
}
