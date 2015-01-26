#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool is_leap(const int &year)
{
	if(year % 100){
		return year % 4 == 0;
	}else{
		return year % 400 == 0;
	}
}

int main()
{
	int n, i;
	int year, month, day;
	int day_of_week;
	int year_day;
	const char weekday_name[7][20] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	while(scanf("%d", &n) == 1 && n >= 0){
		//start from January 1st, 2000, Saturday
		year = 2000;
		month = 0;
		day = 0;
		day_of_week = (6 + n % 7) % 7;
		
		while(true){
			if(is_leap(year)){
				year_day = 366;
			}else{
				year_day = 365;
			}
			if(n >= year_day){
				n -= year_day;
				++year;
			}else{
				break;
			}
		}
		
		if(is_leap(year)){
			month_day[1] = 29;
		}else{
			month_day[1] = 28;
		}
		i = 0;
		while(n >= month_day[i]){
			n -= month_day[i];
			++i;
			++month;
		}
		day = n;
		
		printf("%4d-%02d-%02d %s\n", year, month + 1, day + 1, weekday_name[day_of_week]);
	}
	
	return 0;
}
