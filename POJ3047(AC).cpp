#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;
//Zeller formula
//w=y+[y/4]+[c/4]-2c+[26(m+1）/10]+d-1
char wd_name[7][20] = {
	"sunday",
	"monday",
	"tuesday",
	"wednesday",
	"thursday",
	"friday",
	"saturday"
};

int main()
{
	int year, month, day;
	int week_day;
	int y, c, m, d;

	while(scanf("%d%d%d", &year, &month, &day) == 3){
		if(month == 1 || month == 2){
			m = month + 12;
			--year;
		}else{
			m = month;
		}
		y = year % 100;
		c = year / 100;
		d = day;
		week_day = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(26 * (m + 1) / 10) + d - 1;
		if(week_day >= 0){
			week_day = week_day % 7;
		}else{
			week_day = (7 - (7 - week_day) % 7) % 7;
		}

		printf("%s\n", wd_name[week_day]);
	}

	return 0;
}

