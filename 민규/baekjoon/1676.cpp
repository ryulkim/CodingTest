#include <iostream>
#include <vector>
using namespace std;
vector<long long> dynamic(501, 1);
vector<int> data_d(501, 0);
const int divide_n = 1000000000;

int main(void)
{
	int answer = 0;

	for (int x = 2; x <= 500; x++)
	{
		dynamic[x] = (x * dynamic[x - 1])%divide_n;

		while (dynamic[x] % 10 == 0)
		{
			answer++; dynamic[x] /= 10;
		}

		data_d[x] = answer;
	}

	int n; cin >> n;
	cout << data_d[n] << "\n";

	return 0;
}
