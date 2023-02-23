#include <iostream>
#include <vector>
using namespace std;


int n;
vector<int> data_l(501,0);
vector<int> data_l2(501, 0);
vector<int> where0;

int solution()
{
	int answer = 0;

	for (int x = 0; x < n; x++)
	{
		int data1, data2; cin >> data1 >> data2;
		data_l[data1] = data2;
	}

	for (int x = 1; x <= 500; x++)
	{
		if (data_l[x] == 0) { continue; }

		for (auto y = where0.begin(); y != where0.end(); y++)
		{
			if (data_l[x] >  data_l[*y])
			{	
				data_l2[x] = max(data_l2[x], data_l2[*y] + 1);
			}
		}	

		where0.push_back(x);
		data_l2[x] = max(data_l2[x], 1);
	}

	for (int x = 1; x <= 500; x++)
		answer = max(answer, data_l2[x]);
		
	return n - answer;
}

int main(void)
{
	cin >> n;
	cout << solution() << "\n";

	return 0;
}
