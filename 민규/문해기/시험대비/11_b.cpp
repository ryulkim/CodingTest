#include <iostream>
#include <vector>
using namespace std;


int n;
vector<vector<char>> map0;
vector<int> count_m;
int size_r = 0; int size_b = 0;


int solution(int n0,int x0 ,int y0)
{
	if (n0 == 1)
	{
		if (map0[x0][y0] == 'R') return 0;
		else return 1;
	}

	int n_s = n0 / 2;

	int l_h = solution(n_s, x0, y0);
	int l_l = solution(n_s, x0 + n_s, y0);
	int r_h = solution(n_s, x0, y0 + n_s);
	int r_l = solution(n_s, x0 + n_s, y0 + n_s);

	if ((l_h == l_l) && (l_h == r_h) && (l_h == r_l))
	{
		if (n0 == n) count_m[l_h]++;

		return l_h;
	}

	else
	{
		count_m[l_h]++; count_m[l_l]++;
		count_m[r_h]++; count_m[r_l]++;
	}

	return 2;
}


int main(void)
{
	int t; cin >> t;
	for (int x = 0; x < t; x++)
	{
		cin >> n; map0.assign(n, vector<char>(n, 0));
		count_m.assign(3, 0);
		size_r = 0; size_b = 0;

		for (int y = 0; y < n; y++)
		{
			for (int z = 0; z < n; z++) {
				cin >> map0[y][z];

				if (map0[y][z] == 'R') size_r++;
				else size_b++;
			}
		}

		solution(n,0,0);

		cout << count_m[0] << " " << size_r << " " << count_m[1] << " " << size_b << "\n";
	} //mak_map

	return 0;
}
