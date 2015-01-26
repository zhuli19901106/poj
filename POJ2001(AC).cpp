#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
	string word;
	string prefix;
}st;

string get_prefix(string s1, string s2)
{
	int i;

	i = 0;
	while(i < (int)s1.size() && i < (int)s2.size() && s1[i] == s2[i]){
		++i;
	}

	if(i >= (int)s1.size()){
		return string(s1);
	}else{
		return s1.substr(0, i + 1);
	}
}

int main()
{
	int i;
	st mst;
	map<string, int> msi;
	map<string, int>::iterator msiit;
	map<int, string> mis;
	map<int, string>::iterator misit;
	vector<string> v;
	vector<st> v0;
	string str, str1, str2;
	
	v.clear();
	v0.clear();
	mis.clear();
	msi.clear();
	i = 0;
	while(cin >> str){
		v.push_back(str);
		mis.insert(pair<int, string>(i, str));
		msi.insert(pair<string, int>(str, i));
		mst.prefix = "";
		mst.word = str;
		v0.push_back(mst);
		++i;
	}
	sort(v.begin(), v.end());

	str2 = get_prefix(v[0], v[1]);
	msiit = msi.find(v[0]);
	i = msiit->second;
	v0[i].prefix = str2;

	for(i = 1; i < (int)v.size() - 1; ++i){
		str1 = get_prefix(v[i], v[i - 1]);
		str2 = get_prefix(v[i], v[i + 1]);
		msiit = msi.find(v[i]);
		if(str1.size() < (int)str2.size()){
			v0[msiit->second].prefix = str2;
		}else{
			v0[msiit->second].prefix = str1;
		}
	}

	str1 = get_prefix(v[v.size() - 1], v[v.size() - 2]);
	msiit = msi.find(v[v.size() - 1]);
	i = msiit->second;
	v0[i].prefix = str1;

	for(i = 0; i < (int)v0.size(); ++i){
		cout << v0[i].word << " " << v0[i].prefix << endl;
	}

	//clear up the data
	v0.clear();
	v.clear();

	return 0;
}
