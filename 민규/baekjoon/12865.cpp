#include <iostream>
#include <vector>
using namespace std;

int n, wei_max;
vector<int> bag0;
vector<int> bag00;

int main(void)
{
	cin >> n >> wei_max; int answer = 0;
	bag0.assign(wei_max + 1, 0); bag00.assign(wei_max + 1, 0);

	for (int x = 0; x < n; x++)
	{
		int data_wei, data_val; cin >> data_wei >> data_val;

		int d_wei = data_wei; int d_val = data_val;

		if (wei_max - d_wei >= 0)
		{
			for (int y = 1; y + d_wei < bag0.size(); y++)
			{	
				if (bag0[y] == 0) continue;
				bag00[y + d_wei] = max(bag0[y + d_wei], bag0[y] +  d_val);
				answer = max(answer, bag00[y + d_wei]);
			}

			bag00[d_wei] = max(bag00[d_wei], d_val);
			answer = max(answer, bag00[d_wei]);

			for (int y = 1; y < bag0.size(); y++)
				bag0[y] = bag00[y];
		}
	}

	cout << answer << "\n";
	return 0;
}
