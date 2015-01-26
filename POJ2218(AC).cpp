#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct node{
	string name;
	int day_on_diet;
	int start_weight;
	int current_weight;
}Node;

void swap(Node &a, Node &b)
{
	Node t;
	
	t = a;
	a = b;
	b = t;
}

void my_sort(Node a[], int n)
{
	int i, j;
	
	for(i = 0; i < n - 1; ++i){
		for(j = i + 1; j < n; ++j){
			if(a[i].current_weight < a[j].current_weight){
				swap(a[i], a[j]);
			}
		}
	}
}

int main()
{
	string s;
	Node a[50];
	int i, n;
	int case_count;
	
	case_count = 0;
	while(cin >> s){
		n = 0;
		while(true){
			cin >> a[n].name;
			if(a[n].name == "END"){
				break;
			}else{
				cin >> a[n].day_on_diet >> a[n].start_weight;
				a[n].current_weight = a[n].start_weight - a[n].day_on_diet;
				++n;
			}
		}
		++case_count;
		if(case_count > 1){
			cout << endl;
		}
		if(n > 0){
			my_sort(a, n);
		}
		for(i = 0; i < n; ++i){
			cout << a[i].name << endl;
		}
	}
	
	return 0;
}
