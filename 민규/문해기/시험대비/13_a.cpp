#include <iostream>
#include <vector>
#include <string>
using namespace std;


int n, m;
string s;
string orig = "";


vector<int> s_gra;

int find()
{
	int count = 0;

	for (int x = 0; x < orig.length(); x++)
	{
		if (orig[x] == s[count]) { count++; }
		else if (count > 0) { count = s_gra[count - 1]; x--; }
	
		if (count == s.length()) return 1;
	}

	return 0;
}

int solution()
{
	vector<string> orig1(n, "");
	vector<string> orig2(n, "");
	vector<string> orig3(2*n - 1, "");

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++)
		{
			char data; cin >> data;
			orig1[x] += data;
			orig2[y] += data;
			orig3[n-1 + (x - y)] += data;
		}
	}

	for (int x = 0; x < n; x++)
	{
		orig += orig1[x] + '$';
		orig += orig2[x] + '$';
		orig += orig3[x] + '$';
	}

	for (int x = n; x < 2*n-1; x++)
	{
		orig += orig3[x] + '$';
	}

	for (int x = 0; x < m; x++)
	{
		cin >> s; s_gra.assign(s.length(), 0);
		int b = 0;

		for (int y = 1; y < s_gra.size(); y++)
		{	
			while (s[y] != s[b] && b > 0) b = s_gra[b - 1];	
			if (s[y] == s[b]) s_gra[y] = ++b;
		}

		cout << find() << "\n";
	}

	return 0;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	solution();
	return 0;
}
