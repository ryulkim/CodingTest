
#include <iostream>
#include <vector>

using namespace std;


int answer = 0;
const int left_top = -1; const int right_top = 0;
const int inf = 123456789; int n;
vector<vector<int>> tower;

int solution()
{
	tower.assign(0, vector<int>(0, 0)); int block_0; answer = inf;
	vector<int> root(1, 0); cin >> root.front(); tower.push_back(root);
	
	for (int x = 1; x < n ; x++)
	{
		vector<int> tower_layer;

		for (int y = 0; y <= x; y++)
		{
			int left_side = inf, right_side = inf;

			if (0 <= y + left_top && y + left_top < x)
				left_side = tower[x - 1][y +left_top];

			if (0 <= y + right_top && y + right_top < x)
				right_side = tower[x - 1][y + right_top];

			int weight = (min(left_side, right_side) != inf) ? min(left_side, right_side) : 0;
			cin >> block_0; tower_layer.push_back(block_0 + weight);
		}

		tower.push_back(tower_layer);
	}

	for(int x = 0 ; x < tower[n-1].size() ; x++)
	 answer = min(answer,tower[n-1][x]);

	return answer;
}



int main(void)
{
	int all_case; cin >> all_case;

	for (int x = 0; x < all_case; x++)
	{
		cin >> n; cout << solution() << "\n";
	}

	return 0;
}
