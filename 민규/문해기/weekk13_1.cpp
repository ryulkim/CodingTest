#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const vector<vector<int>> search1 = { { 0 , 1 }, { 1 , 0 }, { 1 , 1 } };
const int alpa_n = 65;
int size_0, word_n;
vector<vector<char>> map0;
vector<vector<int>> index0x;
vector <vector<int>> index0y;
bool answer = 0;
string s;


int find(int x0, int y0, int len,int mode)
{
	len++; int x1, y1;
	if (len == s.size()) { answer = 1; return 1;}

	x1 = x0 + search1[mode][0]; y1 = y0 + search1[mode][1];

	if (x1 < size_0 && y1 < size_0 && s[len] == map0[x1][y1])
		return find(x1, y1, len,mode);
		
	return 0;
}

int solution()
{
	map0.assign(size_0, vector<char>(size_0, '@'));
	index0x.assign(26, vector<int>(0,0)); index0y.assign(26, vector<int>(0, 0));

	for (int x = 0; x < size_0; x++)
	{
		for (int y = 0; y < size_0; y++)
		{
			char data0;  cin >> data0; map0[x][y] = data0;
			index0x[(int)(data0 - alpa_n)].push_back(x);
			index0y[(int)(data0 - alpa_n)].push_back(y);
		}
	}

	for (int x = 0; x < word_n; x++)
	{
		answer = 0; cin >> s;
		auto index_tx = index0x[(int)(s[0] - alpa_n)];
		auto index_ty = index0y[(int)(s[0] - alpa_n)];

		auto yx = index_tx.begin(); auto yy = index_ty.begin();

		for (1; yx != index_tx.end() && yy != index_ty.end(); yx++, yy++)
		{
			for (int z = 0; z < s.length(); z++)
				if (index0x[(int)(s[z] - alpa_n)].size() == 0)
					goto loop1;

			for (int z = 0; z < 3; z++)
				if (find(*yx, *yy, 0, z))
					goto loop1;
		}

		loop1:;
		cout << answer << "\n";
	}

	return 1;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> size_0 >> word_n;
	solution();
	return 0;
}
