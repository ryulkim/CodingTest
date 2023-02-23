#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;


int solution()
{
	int answer = 0;
	int prefix = 0;
	vector<pair<int,int>> m_list;

	for (int x = 0; x < n; x++)
	{
		int data; cin >> data;

		if (x == 0) m_list.push_back(pair<int,int>(data, 1));

		else
		{
			int stack_count = 0;

			for (int x = 0; x < m_list.size(); x++)
			{
				if (data > m_list[x].first)
					stack_count = max(stack_count, m_list[x].second);
			}

			m_list.push_back(pair<int, int>(data, stack_count+1));
		}	
	}

	for (int x = 0; x < m_list.size(); x++)
		answer = max(answer, m_list[x].second);

	return answer;
}


int main(void)
{
	int t; cin >> t;

	for (int x = 0; x < t; x++)
	{
		cin >> n; cout << solution() << "\n";
	}

	return 0;
}
