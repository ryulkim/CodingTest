#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

vector<int> num0;
list<char> sign;
string s; int answer = 0;

int main(void)
{
	cin >> s; string s0 = "";
	sign.push_back('+');

	for (int x = 0; x < s.size();x++)
	{
		if (s[x] == '+' || s[x] == '-')
		{
			num0.push_back(stoi(s0)); s0 = "";
			sign.push_back(s[x]);
		}

		else s0 += s[x];
	}

	num0.push_back(stoi(s0));
	char sign0 = sign.front();

	for (int x = 0; x < num0.size(); x++)
	{
		char sign1 = sign.front();

		if (sign0 == '+' && sign1 == '+') answer += num0[x];
		else if (sign0 == '+' && sign1 == '-') { answer -= num0[x]; sign0 = '-';}
		else if (sign0 == '-' && sign1 == '+') { answer -= num0[x];}
		else if (sign0 == '-' && sign1 == '-') { answer -= num0[x]; sign0 = '-';}
		
		sign.pop_front();

		//cout << num0[x] << " " << answer << "\n";
	}

	cout << answer << "\n";
	return 0;
}
