#include <iostream>
#include <deque>
#include <string>

using namespace std;

string command_0, line_0;
deque<int> line;
int reverse_mode = 0;

void solution()
{
	if (line.size() == 0) { reverse_mode = 2; return;}
	if (reverse_mode == 0) line.pop_front();
	else line.pop_back();
}

void print()
{
	if (reverse_mode == 2) { cout << "error\n"; return;}

	cout << "["; 

	if (line.size() > 0) {

		if (reverse_mode == 0) {
			for (int x = 0; x < line.size() - 1; ++x) { cout << line[x] << ","; }
			cout << line.back();
		}

		else
		{
			for (int x = line.size() - 1; x > 0; --x) { cout << line[x] << ","; }
			cout << line.front();
		}
	}

	cout << "]\n";
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t_case; cin >> t_case;

	for (int x = 0; x < t_case; ++x)
	{
		reverse_mode = 0; line.assign(0, 0);

		cin >> command_0;
		int num_len; cin >> num_len >> line_0;	
		
		string num = "";
		for (int x = 0; x < line_0.size(); ++x)
		{
			if (line_0[x] >= '0' && line_0[x] <= '9') {num += line_0[x];}
			else { if (num.size() > 0)line.push_back(stoi(num)); num = "";}
		}

		for (int x = 0; x < command_0.size(); ++x)
		{
			if (reverse_mode == 2) { break; }
			if (command_0[x] == 'R') { reverse_mode = !reverse_mode; }
			else solution();
		}
	
		print();
	}

	return 0;
}
