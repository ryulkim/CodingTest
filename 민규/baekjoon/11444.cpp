#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> data;
long long n;
long long mod = 1000000007;

vector<vector<long long>> multiple(vector<vector<long long>>& a, vector<vector<long long>>& b)
{
	vector<vector<long long>> data0(2, vector<long long>(2, 0));

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			for (int z = 0; z < 2; z++)
			{
				data0[x][y] += (a[x][z] * b[z][y]) % mod;
				data0[x][y] %= mod;
			}
		}
	}

	return data0;
}


int main(void)
{
	cin >> n;

	vector<vector<long long>> ori = { {1,0} , {0,1} };
	vector<vector<long long>> mulp = { {1,1} , {1,0} };

	while (n > 0)
	{
		if (n %2 == 1)
			ori = multiple(ori, mulp);

		mulp = multiple(mulp, mulp);
		n /= 2;
	}

	cout << ori[0][1] << "\n";
	return 0;
}
