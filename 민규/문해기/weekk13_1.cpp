#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int size_0, word_n;
string check_list0;
string check_list1;
string check_list2;

bool answer = 0;
string s;

int kmp_a(string long_s, vector<int>& fail_f)
{
	int start_n = 0;

	for (int x = 0; x < long_s.size(); x++)
	{
		if (long_s[x] != s[start_n]) {

			if (start_n > 0) { start_n = fail_f[start_n - 1]; x--;}
			continue;
		}

		else
		{ 
		  start_n++;
		}

		if (start_n == s.size()) return 1;
	}
	
	return 0;
}


vector<int> KMP_GET() {

	int Begin = 0, Length = (int)s.size();

	vector<int> pi(Length, 0);

	for (int i = 1; i < Length; i++) {

		while (s[i] != s[Begin] && Begin > 0)Begin = pi[Begin - 1];

		if (s[i] == s[Begin]) pi[i] = ++Begin;

	}

	return pi;
}


int find0()
{
	vector<int> fail_f = KMP_GET();
	
	if (kmp_a(check_list0, fail_f))
	  return 1;

	if (kmp_a(check_list1, fail_f))
	  return 1;

	if (kmp_a(check_list2, fail_f))
	  return 1;
	
	return 0;
}

int solution()
{
	vector<string> check_list00, check_list10, check_list20;
	check_list00.assign(size_0, ""); check_list10.assign(size_0, ""); check_list20.assign(size_0 * 2, "");
	
	for (int x = 0; x < size_0; x++)
	{
		for (int y = 0; y < size_0; y++)
		{
			char data0; cin >> data0;
			check_list00[x] += data0; check_list10[y] += data0; check_list20[x - y + size_0] += data0;
		}
	}

	for (int x = 0; x < size_0; x++) {
		check_list0 += (check_list00[x] + '$');
	}
					
	for (int x = 0; x < size_0; x++) {
		check_list1 += (check_list10[x] + '$');
	}

	for (int x = 0; x < size_0 * 2; x++) {
		check_list2 += (check_list20[x] + '$');
	}

	for (int x = 0; x < word_n; x++)
	{
		answer = 0; cin >> s;

		if (find0())
		  cout << true << "\n"; 
			
		else cout << false << "\n";
	}

	return 1;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> size_0 >> word_n;
	solution();
	return 0;
}
