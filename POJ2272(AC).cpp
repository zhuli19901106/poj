#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double a[2][3][2];
	double r[2][3];
	int score[2];
	int i, j;

	while (true) {
		scanf("%lf", &a[0][0][0]);
		scanf("%lf", &a[0][0][1]);
		scanf("%lf", &a[0][1][0]);
		scanf("%lf", &a[0][1][1]);
		scanf("%lf", &a[0][2][0]);
		scanf("%lf", &a[0][2][1]);
		scanf("%lf", &a[1][0][0]);
		scanf("%lf", &a[1][0][1]);
		scanf("%lf", &a[1][1][0]);
		scanf("%lf", &a[1][1][1]);
		scanf("%lf", &a[1][2][0]);
		scanf("%lf", &a[1][2][1]);
		if (a[0][0][0] <= -100.0) {
			break;
		}

		for (i = 0; i < 3; ++i) {
			for (j = 0; j < 2; ++j) {
				r[j][i] = sqrt(a[j][i][0] * a[j][i][0] + a[j][i][1] * a[j][i][1]);
			}
		}

		score[0] = score[1] = 0;
		for (i = 0; i < 3; ++i) {
			for (j = 0; j < 2; ++j) {
				if (r[j][i] <= 3.0) {
					score[j] += 100;
				} else if (r[j][i] <= 6.0) {
					score[j] += 80;
				} else if (r[j][i] <= 9.0) {
					score[j] += 60;
				} else if (r[j][i] <= 12.0) {
					score[j] += 40;
				} else if (r[j][i] <= 15.0) {
					score[j] += 20;
				}
			}
		}

		printf("SCORE: %d to %d, ", score[0], score[1]);
		if (score[0] < score[1]) {
			printf("PLAYER 2 WINS.\n");
		} else if (score[0] > score[1]) {
			printf("PLAYER 1 WINS.\n");
		} else {
			printf("TIE.\n");
		}
	}

	return 0;
}