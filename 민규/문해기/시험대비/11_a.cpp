#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int alpa_n = 26;
vector<int> alpa_list(alpa_n, 0);
int n;
vector<vector<pair<char,int>>> word_list;
vector<int> word_score;

int f_score = 0;

int solution(int,int);

int find_word(int score, int index)
{
	for (auto x = word_list[index].begin() ; x != word_list[index].end(); x++)
	{
	
		if (alpa_list[x->first - 'a'] - (x->second) >= 0)
			alpa_list[x->first - 'a'] -= (x->second);

		else
		{
			f_score = max(f_score, score);

			for(auto y = word_list[index].begin(); y != x ; y++)
				alpa_list[y->first - 'a'] += (y->second);

			return 0;
		}
	}
	
	solution(score + word_score[index],index+1);

	for (auto x = word_list[index].begin(); x != word_list[index].end(); x++)
	{
		alpa_list[x->first - 'a'] += (x->second);
	}

	return 1;
}



int solution(int score, int index_z)
{
	f_score = max(f_score, score);

	for (int x = index_z; x < word_list.size(); x++)
	{
		find_word(score, x);
	}

	return f_score;
}

int word_map(string& s)
{
	vector<pair<char,int>> word_comp;
	sort(s.begin(), s.end());

	int count = 0; char prefix = s.front();
	for (int x = 0; x < s.length(); x++)
	{
		if (s[x] == prefix) count++;

		else {

			word_comp.push_back(pair<char, int>(prefix, count));
			prefix = s[x]; count = 1;
		}
	}

	word_comp.push_back(pair<char, int>(prefix, count));
	word_list.push_back(word_comp);
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int x = 0; x < alpa_n ; x++)
		cin >> alpa_list[x];

	cin >> n;
	for (int x = 0; x < n; x++)
	{  
		string s; int s_d; cin >> s >> s_d;	
		word_map(s); word_score.push_back(s_d);	
	}

	cout << solution(0,0) << "\n";
	return 0;
}
