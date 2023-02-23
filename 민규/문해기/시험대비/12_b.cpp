#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(pair<int, int>& i, pair<int, int>& j)
{
	if (i.second == j.second)
		return i.first >= j.first;

	else return i.second <= j.second;
}

int solution()
{
	vector<pair<int, int>> map0;
	
	int m; cin >> m; int answer = 1;
	for (int x = 0; x < m; x++)
	{
		int score, meter; cin >> score >> meter;
		map0.push_back(pair<int, int>(score, meter));
	}

	sort(map0.begin(), map0.end(), compare);
	int prefix_s = map0.front().first;

	for (int x = 1; x < map0.size(); x++)
	{
	 if (prefix_s < map0[x].first) { answer++; prefix_s = map0[x].first;}	
	}

	return answer;
}


int main(void)
{
	int t; cin >> t;


	for (int x = 0; x < t; x++)
	{
		cout << solution() << "\n";
	}

	return 0;
}
