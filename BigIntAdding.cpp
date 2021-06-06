#include <iostream>
#include <sstream>
#define ctoi(x) (x-'0')
using namespace std;

int main() {
	int n;
	int k = 1;
	cin >> n;

	while (n--)
	{
		string a, b;
		cin >> a >> b;

		int lena = a.size();
		int lenb = b.size();
		int lenmax = lena > lenb ? lena : lenb;
		int lenmin = lena < lenb ? lena : lenb;
		int flag = 0;

		stringstream sstr;

		for (int i = -1; i >= (0 - lenmin); i--) {
			int sum = ctoi(a[lena + i]) + ctoi(b[lenb + i]) + flag;

			if (sum >= 10)
			{
				sstr << sum - 10;
				flag = 1;
			}
			else
			{
				sstr << sum;
				flag = 0;
			}
		}

		for (int i = 0 - lenmin - 1; i >= (0 - lenmax); i--)
		{
			int sum = ctoi((lena > lenb ? a : b)[lenmax + i]) + flag;
			if (sum >= 10)
			{
				sstr << sum - 10;
				flag = 1;
			}
			else
			{
				sstr << sum;
				flag = 0;
			}
		}

		if (flag == 1)
		{
			sstr << flag;
		}

		string res = sstr.str();
		reverse(res.begin(), res.end());


		cout << "Case " << k++ << ":" << endl;
		cout << a << " + " << b << " = ";
		cout << res << endl;

		if (n)
		{
			cout << endl;
		}
	}

	return 0;
}
