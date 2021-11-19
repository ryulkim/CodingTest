#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int index_a = 97;
const int count_a = 26;
vector<int> alpa_num(count_a, 0);
vector<pair<string,int>> menu;
int max_count0 = 0;


void healing(vector<pair<int, int>>& call0)
{
	for (int x = 0; x < call0.size(); x++)
	{
		alpa_num[call0[x].first] += call0[x].second;
	}
}


vector<pair<int, int>> dfs(int m_0, int count0)
{
	int count = 0; char inde_0 = menu[m_0].first.front();
	vector<pair<int, int>> call0;

	for (int x = 0; x < menu[m_0].first.length(); x++)
	{
		if (inde_0 == menu[m_0].first[x])
			count++;

		else
		{
		  if (alpa_num[int(inde_0) - index_a] - count < 0)
		  {
		    max_count0 = max(max_count0, count0); 
		    return call0;
		  }

		  alpa_num[int(inde_0) - index_a] -= count;
		  call0.push_back(pair<int, int>(int(inde_0) - index_a, count));
		  inde_0 = menu[m_0].first[x]; count = 1;
		}
	}

	if (alpa_num[int(inde_0) - index_a] - count < 0)
	{
		max_count0 = max(max_count0, count0);
		return call0;
	}

	alpa_num[int(inde_0) - index_a] -= count;
	call0.push_back(pair<int, int>(int(inde_0) - index_a, count)); 
	max_count0 = max(max_count0, count0 + menu[m_0].second);

	for (int x = m_0+1; x < menu.size(); x++)
	{		
	  vector<pair<int, int>> a = dfs(x, count0 + menu[m_0].second);
	  healing(a);			
	}
    
	return call0;
}



int solution()
{
	for (int x0 = 0; x0 < menu.size(); x0++)
	{
	  vector<pair<int, int>> a = dfs(x0, 0);
	  healing(a);
	}

	return max_count0;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int num0;
	for (int x = 0; x < count_a; x++)
	{
		cin >> num0;
		alpa_num[x] = num0;
	}

	cin >> num0;

	for (int x = 0; x < num0; x++)
	{
		string s; int n; cin >> s >> n;
		sort(s.begin(), s.end());
		menu.push_back(pair<string, int>(s, n));
	}

	cout << solution() << "\n";
	return 0;
}
