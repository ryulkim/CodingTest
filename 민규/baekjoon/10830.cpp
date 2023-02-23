#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<vector<int>> a_v0;
int n0; long long int m0;

const int divide_n = 1000;

vector<vector<int>> multiple(vector<vector<int>>& av_1, vector<vector<int>>& av_2)
{
	vector<vector<int>> a_v3(n0,vector<int>(n0,0));

	for (int x = 0; x < n0; ++x) {
		for (int y = 0; y < n0; ++y)
		{
			for (int z = 0; z < n0; ++z) {
				a_v3[x][y] += (av_1[x][z] * av_2[z][y]) % divide_n;
				a_v3[x][y] %= divide_n;
			}
		}
	}

	return a_v3;
}

vector<vector<int>> solution(long long int pow0)
{
	if (pow0 == 1) return a_v0;
	
	vector<vector<int>> answer = solution(pow0/2);
	vector<vector<int>> answer_2 = multiple(answer, answer);

	if (pow0 % 2 == 0) return answer_2;
	else return multiple(a_v0, answer_2);
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n0 >> m0;
	a_v0.assign(n0, vector<int>(n0, 0));

	for (int x = 0; x < n0; ++x) {
		for (int y = 0; y < n0; ++y)
		{
			cin >> a_v0[x][y]; a_v0[x][y] %= divide_n;
		}
	}

	vector<vector<int>> answer_0 = solution(m0);

	for (int x = 0; x < n0; ++x) {
		for (int y = 0; y < n0; ++y) {
			cout << answer_0[x][y] << " ";
		}

		cout << "\n";
	}

	return 0;
}
