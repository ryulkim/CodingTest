#include <iostream>
#include <vector>
using namespace std;


int n; vector<pair<int,int>> data_l;


int solution()
{
	int answer = 0;

	for (int x = 0; x < n; x++)
	{
		int data; cin >> data; int min_line = 1;

		for (auto y = data_l.begin(); y != data_l.end(); y++)
		{
			if ((*y).first < data)
			{
				min_line = max(min_line, (*y).second + 1);
			}
		}

		data_l.push_back(pair<int, int>(data, min_line));
		answer = max(answer, min_line);
	}

	return answer;
}

int main(void)
{
	cin >> n;
	cout << solution() << "\n";

	return 0;
}
