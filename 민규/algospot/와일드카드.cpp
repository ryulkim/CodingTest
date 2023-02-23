#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string w;
string s;
vector<string> listen;
vector<vector<int>> read_data;

int match(int w0, int s0)
{
	int& ret = read_data[w0][s0];
	

	if (ret != -1) return ret;

	while (w0 < w.size() && s0 < s.size() && (w[w0] == '?' || w[w0] == s[s0]))
	{
		++w0; ++s0;
	}


	if (w0 == w.size()) return (s0 == s.size());

	if (w[w0] == '*')
		for (int skip = 0; skip + s0 <= s.size(); ++skip)
		{
			if (match(w0 + 1, s0 + skip) == 1) return (ret = 1);
		}

	return (ret = 0);
}


int main(void)
{
	int n; cin >> n;

	for (int x = 0; x < n; ++x)
	{
		cin >> w;
	
		int n1; cin >> n1; listen.assign(n1, "");

		for (int y = 0; y < n1; ++y)
		{
			cin >> listen[y];
		}

		sort(listen.begin(), listen.end());

		for (int y = 0; y < n1; ++y)
		{
			read_data.assign(101, vector<int>(101, -1));

			s = listen[y];
			if (match(0, 0) == 1)
				cout << s << "\n";
		}
	}

	return 0;
}
