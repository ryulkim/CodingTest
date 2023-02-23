#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> cloth; int m;
vector<int> cloth_n;

int solution()
{
	cloth.assign(0, "");  cloth_n.assign(0, 0);  int answer = 1;

	for (int x = 0; x < m; x++)
	{
		string s1, s2; cin >> s1 >> s2;

		for (int y = 0; y < cloth.size(); y++)
		{
			if (cloth[y] == s2)
			{
				cloth_n[y]++; goto loop1;
			}
		}

		cloth.push_back(s2); cloth_n.push_back(1);
		loop1:;		
	}

	for (int y = 0; y < cloth_n.size(); y++)
	{
		answer *= (cloth_n[y] + 1);
	}

	return answer - 1;
}


int main(void)
{
	int t_case; cin >> t_case;

	for (int x = 0; x < t_case; x++)
	{
		cin >> m;
		cout << solution() << "\n";
	}

	return 0;
}
