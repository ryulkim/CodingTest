#include <iostream>
#include <string>
#include <vector>
using namespace std;


string s1, s2;
vector<vector<int>> def;
int answer = 0;

int solution()
{
	int value = 0;

	for (int y = 0; y < s2.length(); y++)
	{
		if (s1.front() == s2[y]) value = 1;
		def[0][y] = value;

		answer = max(answer, def[0][y]);
	}
	for (int x = 1; x < s1.length(); x++)
	{
		int check_a = 0; answer = 0;

		for (int y = 0; y < s2.length(); y++)
		{
			int index_x = (x - 1 >= 0) ? x - 1 : 0;
			int index_y = y - 1;

			if(index_y >= 0) def[x][y] = def[index_x][index_y];
			
			if (s1[x] == s2[y])
			{
				check_a = 1; def[x][y]++;
			}

			if(y-1 >= 0) def[x][y] = max(def[x][y], def[x][y-1]);
			if(x-1 >=0) def[x][y] = max(def[x][y], def[x-1][y]);

			answer = max(answer, def[x][y]);		
		}
	}

	return answer;
}


int main(void)
{
	cin >> s1 >> s2;

	if (s1.length() > s2.length())
	{
		string s = s1; s1 = s2; s2 = s;
	}

	def.assign(s1.length(), vector<int>(s2.length(), 0));
	cout << solution() << "\n";

	return 0;
}
