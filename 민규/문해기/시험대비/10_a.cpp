#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

const int max_size = 10000; int a, b;
vector<int> room;
vector<int> reversed_room;
list<int> queue01;


int change_room(int& where1)
{
	string alpa = to_string(where1);
	string beta = "";

	reverse(alpa.begin(), alpa.end());
	beta += alpa;

	for (int x = beta.length(); x < 4; x++)
		beta.push_back('0');

	return stoi(beta);
}


int visit(int time)
{
	int qs = queue01.size();
	
	for (int y = 0 ;  y < qs ; y++)
	{
		auto x = queue01.front();

		if (x == b) return time;
		room[x] = 0;

		if (x - 1 >= 0 && room[x - 1])
			queue01.push_back(x - 1);
			
	
		if (x + 1 < max_size && room[x + 1])
			queue01.push_back(x + 1);
		

		if (room[reversed_room[x]])
			queue01.push_back(reversed_room[x]);

		queue01.pop_front();
	}

	if (queue01.size())  return visit(time + 1);
	else return 0;
}


int solution()
{
	room.assign(max_size, 1);
	queue01.assign(1,a);

	if (a == b) return 0;
	else return visit(0);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int x = 0; x < 10000; x++)
	{
		reversed_room.push_back(change_room(x));
	}
 
	int t; cin >> t;

	for (int x = 0; x < t; x++)
	{
		cin >> a >> b; cout << solution() << "\n";
	}

	return 0;
}
