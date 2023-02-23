#include <iostream>
#include <vector>
#include <string>
using namespace std;


const string answer[2] = { "NO" ,"YES" };
vector<vector<int>> map_0;
vector<vector<int>> state_0;
int size_0;

int jump2(int y, int x)
{
	if (y >= size_0 || x >= size_0) return 0;
	if (x == size_0 - 1 && y == size_0 - 1) return 1;
	if (state_0[y][x] == 0) return 0;

	state_0[y][x] = jump2(y + map_0[y][x], x) || jump2(y, x + map_0[y][x]);
	return state_0[y][x];
}


int main(void)
{
	int n; cin >> n;

	for (int x = 0; x < n; x++)
	{
		cin >> size_0; 
		map_0.assign(size_0, vector<int>(size_0, 0));
		state_0.assign(size_0, vector<int>(size_0, 1));

		for(int y = 0; y < size_0; y++)
			for (int z = 0; z < size_0; z++)
			{
				cin >> map_0[y][z];
			}

		cout << answer[jump2(0, 0)] << "\n";
	}

	return 0;
}
