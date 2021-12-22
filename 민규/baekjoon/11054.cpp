#include <iostream>
#include <vector>
using namespace std;


int n; vector<pair<int,int>> data_l;
vector<pair<int, int>> data_l2;
vector<int> data0;


int solution()
{
	int answer = 0;

	for (int x = 0; x < n; x++)
	{
		int data; cin >> data; int min_line = 1;
		data0.push_back(data);

		for (auto y = data_l.begin(); y != data_l.end(); y++)
		{
			if ((*y).first < data)
			{
				min_line = max(min_line, (*y).second + 1);
			}
		}

		data_l.push_back(pair<int, int>(data, min_line));
	}


	for (int x = n-1; x >= 0; x--)
	{
		int data = data0[x]; int min_line = 1;

		for (auto y = data_l2.begin(); y != data_l2.end(); y++)
		{
			if ((*y).first < data)
			{
				min_line = max(min_line, (*y).second + 1);
			}
		}

		data_l2.push_back(pair<int, int>(data, min_line));
	}

	for (int y = 0; y < data_l2.size(); y++)
	{
		answer = max(answer, data_l[data_l2.size() - y - 1].second + data_l2[y].second);
	}

	return answer-1;
}

int main(void)
{
	cin >> n;
	cout << solution() << "\n";

	return 0;
}
