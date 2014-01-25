#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
// x|y = not(x and y)
// x = x
// not x = x|x
// x and y = (x|y)|(x|y)
// x or y = (x|x)|(y|y)
// when n = 2
// ((A1|B1)|(((A0|B0)|(A0|B0))|((A1|A1)|(B1|B1))))

int main()
{
	int n;
	string res[100];
	char str[10000];

	// res[0] = A0 & B0;
	res[0] = "((A0|B0)|(A0|B0))";
	for (int i = 1; i < 100; ++i) {
		sprintf(str, "((A%d|B%d)|(%s|((A%d|A%d)|(B%d|B%d))))", i, i, res[i - 1].c_str(), i, i, i, i);
		res[i] = str;
	}

	while (cin >> n) {
		if (n < 1 || n > 100) {
			continue;
		}
		cout << res[n - 1] << endl;
	}

	return 0;
}