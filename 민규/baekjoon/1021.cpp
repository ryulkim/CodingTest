#include <deque>
#include <iostream>
using namespace std;


deque<int> role;
int answer = 0;


int solution(int alpa)
{
	if (role.front() == alpa) { role.pop_front(); return 0;}

	for (int x = 1; x < role.size(); x++)
	{
		if (role[x] == alpa)
		{
			int d = min(x, (int)(role.size() - x)); answer += d;

			if (x < role.size() - x)
			{
				while (d > 0) { role.push_back(role.front()); role.pop_front(); d--;}
			}

			else
			{
				while (d > 0) { role.push_front(role.back()); role.pop_back(); d--;}
			}
	
			role.pop_front();  break;
		}
	}

	return 0;
}


int main(void)
{
	int n; int index_n; cin >> n >> index_n;

	for (int x = 1; x <= n; ++x) role.push_back(x);


	for (int x = 0; x < index_n; ++x)
	{
		int alpa; cin >> alpa;
		solution(alpa);
	}


	cout << answer << "\n";
	return 0;
}
