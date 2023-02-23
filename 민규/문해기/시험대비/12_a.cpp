
#include <iostream>
#include <vector>
using namespace std;

int n;

int solution()
{
	cin >> n;
	int answer = 987654321;
	vector<vector<int>> trig; 


	for (int x = 0; x < n; x++)
	{
		vector<int> layer;

		for (int y = 0; y <= x; y++)
		{
			int data; cin >> data;

			if (x == 0) { layer.push_back(data); break;}

			if (y == 0) { layer.push_back(data + trig[x - 1][0]);}

			else if(y == x) {layer.push_back(data + trig[x - 1][y-1]); }

			else{ layer.push_back(data + min(trig[x - 1][y],trig[x - 1][y - 1]));}
		}

		trig.push_back(layer);
	}

	for (auto x = trig.back().begin(); x != trig.back().end(); x++)
	{
		answer = min(answer, *x);
	}

	return answer;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;

	for (int x = 0; x < t; x++)
	{
		cout << solution() << "\n";
	}

	return 0;
}
