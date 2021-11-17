#include <iostream>
#include <vector>
using namespace std;

const int watch_size = 15;
const vector<vector<int>> mode = {
	{0,1,2}, //0
	{3,7,9,11}, //1
	{4,10,14,15}, // 2
	{0,4,5,6,7}, // 3 
	{6,7,8,10,12}, // 4
	{0,2,14,15}, // 5
	{3,14,15}, // 6 
	{4,5,7,14,15}, // 7
	{1,2,3,4,5}, // 8
	{3,4,5,9,13} // 9
};

vector<int> watch;
int answer;
const int inf = 9999;


int check_answer(int deepth)
{
	for (int x = 0; x <= watch_size; x++) {

		if (watch[x] != 12)
			goto loop1;
	}

	answer = min(answer, deepth);
	return 1;
	loop1:;

	return 0;
}


int time_spend(int mode_0,int deepth)
{	
	for (int y = 0; y < 4; y++) {

		if (check_answer(deepth + y)) return 1;

		if (mode_0 + 1 <= mode.size())
			time_spend(mode_0 + 1, deepth + y);

		else return 0;


		for (int x = 0; x < mode[mode_0].size(); x++) //case has function
		{
			watch[mode[mode_0][x]] += 3;
			if (watch[mode[mode_0][x]] == 15) watch[mode[mode_0][x]] = 3;
		}	
	}
	
	return 1;
}

int solution()
{
	answer = inf;

	watch.assign(watch_size+1, 0);
	for (int x = 0; x <= watch_size; x++)
	{
		int t; cin >> t; watch[x] = t;
		
	} //input

    time_spend(0,0);

	if (answer == inf)
		answer = -1;
	
	return answer;
}

int main(void)
{
	int all_case; cin >> all_case;

	for (int x = 0; x < all_case; x++)
	{
		cout << solution() << "\n";
	}
	return 0;
}
