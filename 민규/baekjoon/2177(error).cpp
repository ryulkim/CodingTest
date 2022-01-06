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

			answer += (c2 / (m / c1 + m % c1));
			c2 = c2 % (m / c1 + m % c1);

			if(money_v.size() == 0) money_v.push_back(pair<int,int>(c1,c2));

			else if(money_v.back().first >= m)
			{
				answer += c2; money_v.pop_back();
			}

			else
			{
				int d = money_v.front().first;

				money_v.front().second += (m-d)
				money_v.front().first += c1;			
			}
		}
	}

	

	cout << answer << "\n";
	return 0;
}
