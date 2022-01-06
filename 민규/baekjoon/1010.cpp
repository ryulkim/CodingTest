#include <iostream>
#include <vector>
using namespace std;

int n, k0, k1;
vector<long long> river(31, 1);
int divide_n = 1;

int main(void)
{
	for (int x = 2; x <= 30; x++)
	{
		if (river[x - 1] * x >= 0) river[x] = (river[x - 1] * x);
		else { divide_n = x - 1; river[x] = x; }
	}

	int t_case; cin >> t_case;

	for (int x = 0; x < t_case; x++)
	{
		cin >> k0 >> n; k1 = min(k0, n - k0); k0 = max(k0, n - k0);
		long long alpa = 1,beta = 1;

		if (n > divide_n && k0 <= divide_n)
		{
			alpa = (river[divide_n] / river[k0]); beta = river[n];

			if (alpa % river[k1] == 0) alpa /= river[k1];
			else if (beta % river[k1] == 0) beta /= river[k1];
			else { alpa = alpa * beta / river[k1]; beta = 1; };

			alpa *= beta;
		}

		else alpa = (river[n] / river[k0]) / river[k1];

		cout << alpa << "\n";
	}

	return 0;
}
