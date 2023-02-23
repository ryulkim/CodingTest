#include <iostream>
using namespace std;

int n, k0;
const int divide_num = 10007;


int main(void)
{
	cin >> n >> k0; k0 = min(k0, n - k0); n = n - k0; int alpa = 1; int beta = 1;

	for (int x = 1; x <= k0; x++)
	{
		alpa = (alpa * (x + n))%divide_num; 
		beta = (beta * x) % divide_num;
	}

	for (int y = 1; y <= divide_num; y++)
	{
		if ((beta * y) % divide_num == 1)
		{
			alpa = (alpa * y) % divide_num;
			break;
		}
	}

	cout << alpa << "\n";
	return 0;
}
