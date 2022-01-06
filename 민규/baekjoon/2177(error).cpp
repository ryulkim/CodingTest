#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;


int answer = 0;
int n, m;
vector<int> money_n;
list<pair<int,int>> money_v;
list<int> money_g;

int main(void)
{
	cin >> n >> m; money_n.assign(m, 0);

	for (int x = 0; x < n; x++)
	{
		int c1, c2; cin >> c1 >> c2;

		if (c1 >= m) answer += c2;
		else {
			money_v.push_back(pair<int,int>(c1,c2));
		}
	}

	//sort(money_v.begin(), money_v.end());
	money_v.sort();
	int c1 = money_v.back().first; int c2 = money_v.back().second;
	money_v.pop_back();
	money_g.assign(m - c1, c2);

	while (money_v.size())
	{
		int c1 = money_v.back().first; int c2 = money_v.back().second;
		money_v.pop_front();

		while (c2 > 0) {
			for (auto x = money_g.begin(); x != money_g.end(); x++)
			{
				if (c2 > 0) { *x += c1; c2--; }
				else if (*x >= m) { *x = 0; answer++; }
				else goto loop1;
			}
		}

		loop1:;
	}

	int target = 0;

	while (money_g.size())
	{
		target += money_g.back(); money_g.pop_back();
		if (target >= m) { target = 0; answer++;  continue; }
		if (money_g.size() == 0) break;
		target += money_g.front(); money_g.pop_front();
		if (target >= m) { target = 0; answer++;  continue; }
	}

	cout << answer << "\n";
	return 0;
}
