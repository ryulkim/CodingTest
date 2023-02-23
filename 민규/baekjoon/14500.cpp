#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map_o;
int m, n;

int answer = 0;

vector<vector<vector<int>>> block = {
	 {{0,0}, {0,1}, {0,2}, {0,3}} // _ block
	,{{0,0}, {0,1}, {1,0}, {1,1}} // # block
	,{{0,0}, {1,0}, {2,0}, {2,1}} // L block
	,{{0,1}, {1,1}, {2,0}, {2,1}} // L2 block
	,{{0,0}, {1,0}, {1,1}, {2,1}} // N block
	,{{0,1}, {1,0}, {1,1}, {2,0}} // N2 block
	,{{0,0}, {0,1}, {1,1}, {0,2}} // T blcok	
};

vector<vector<int>> index_b = {
	{0,3},{1,1},{2,1},{2,1},{2,1},{2,1},{1,2}
};

vector<vector<int>> for_1;
vector<int> for_1_i;

void formation_1(int data1, int data2)
{
	vector<int> for_data(2, 0);
	for_data.front() = data1;
	for_data.back() = data2;
	for_1_i.front() = max(for_1_i.front(), for_data.front());
	for_1_i.back() = max(for_1_i.back(), for_data.back());

	for_1.push_back(for_data);
}


void formation(int& ind,int mode)
{
	auto block_0 = block[ind];
	auto block_l = index_b[ind];

	for_1.assign(0, vector<int>(0, 0)); for_1_i.assign(2, 0);

	for (auto x = block_0.begin(); x != block_0.end(); x++)
	{
		formation_1((*x).back(), (*x).front());
	}

	block.push_back(for_1); index_b.push_back(for_1_i);
	if (mode == 1) return;

	for_1.assign(0, vector<int>(0, 0)); for_1_i.assign(2, 0);

	for (auto x = block_0.begin(); x != block_0.end(); x++)
	{
		formation_1(block_l.front() - (*x).front(), block_l.back() - (*x).back());
	}

	block.push_back(for_1); index_b.push_back(for_1_i);

	block_0 = block.back();
	for_1.assign(0, vector<int>(0, 0)); for_1_i.assign(2, 0);

	for (auto x = block_0.begin(); x != block_0.end(); x++)
	{
		formation_1((*x).back(), (*x).front());
	}

	block.push_back(for_1); index_b.push_back(for_1_i);
}

int find02(int& m0, int& n0, int& index02)
{
	auto block_e = block[index02];
	int answer = 0;

	if (m0 + index_b[index02].front() >= m || n0 + index_b[index02].back() >= n)
		return -1;

	for (auto x = block_e.begin(); x != block_e.end(); x++)
	{
		if (m0 + (*x).front() < m && n0 + (*x).back() < n)
		{
			answer += map_o[m0 + (*x).front()][n0 + (*x).back()];
		}

		else return -1;
	}
	
	return answer;
}


int find01(int& m0, int& n0)
{
	int answer01 = -1;

	for (int x = 0; x < block.size(); x++)
	{
		answer01 = max(answer01, find02(m0,n0,x));
	}

	return answer01;
}

int solution()
{
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++)
		{
			answer = max(answer, find01(x, y));
		}
	}

	return answer;
}

void print()
{
	for (int x = 0; x < block.size(); x++) {

		vector<vector<int>>data(5, vector<int>(5, 0));

		for (int y = 0; y < block[x].size(); y++)
		{
			data[block[x][y][0]][block[x][y][1]] = 1;
		}

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++)
				cout << data[x][y] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int b_size = block.size();

	for (int x = 0; x < b_size; x++)
	{
		if (x == 1) continue;

		else if (x == 0 || x == 4 || x == 5)
	      formation(x, 1);

		else formation(x, 2);
	}


	//print();
	cin >> m >> n; 
	map_o.assign(m, vector<int>(n, 0));

	for (int x = 0; x < m; x++)
	  for (int y = 0; y < n; y++)
		cin >> map_o[x][y];

	cout << solution() << "\n";
	return 0;
}
