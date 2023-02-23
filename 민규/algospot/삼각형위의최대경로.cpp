#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> trianle;
vector<vector<int>> cache;
int n = 0;


int path2(int y, int x)
{
	if (y == n - 1) return trianle[y][x];

	int& ret = cache[y][x];

	if (ret != -1) return ret;
	return ret = max(path2(y + 1, x), path2(y + 1, x+1)) + trianle[y][x];
}


int main(void)
{
	int n0; cin >> n0;
	
	
	for (int x = 0; x < n0; ++x)
	{
		cin >> n;
		trianle.assign(n, vector<int>(n, 0));
		cache.assign(n, vector<int>(n, -1));
		
		for (int y = 0; y < n; ++y)
		{
			for (int z = 0; z <= y;++z)
			{
				cin >> trianle[y][z];
			}
		}

		cout << path2(0,0) << "\n";
	}

	return 0;
}
