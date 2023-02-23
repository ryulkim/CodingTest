#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<vector<int>> a_v;
vector<vector<int>> b_v;
vector<vector<int>> c_v;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n0, m0; cin >> n0 >> m0;
	a_v.assign(n0, vector<int>(m0, 0));

	for (int x = 0; x < n0; ++x)
		for (int y = 0; y < m0; ++y)
			cin >> a_v[x][y];

	int n1, m1; cin >> n1 >> m1;
	b_v.assign(m1, vector<int>(n1, 0));

	for (int x = 0; x < n1; ++x)
		for (int y = 0; y < m1; ++y)
			cin >> b_v[y][x];
				
	c_v.assign(n0 , vector<int>(m1 , 0));

	
	for (int x = 0; x < n0; ++x) {
		for (int y = 0; y < m1; ++y)
		{
			c_v[x][y] = inner_product(a_v[x].begin(), a_v[x].end(), b_v[y].begin(), 0);
			cout << c_v[x][y] << " ";
		}

		cout << "\n";
	}
	
	return 0;
}
