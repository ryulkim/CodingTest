#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0; int stu_num;
vector<vector<int>> with_case;
vector<int> with_check;

int friend_count(int index_1,int real_1)
{
	if (real_1 >= stu_num)
	{
		with_check[index_1] = 1;
		answer++; return 0;
	}

	if (with_check[index_1] == 0)
		return 0;
	else 
		with_check[index_1] = 0;

	for (int x = 1; x < with_case[index_1].size(); x++)
	{
		if(with_case[index_1][x] < index_1)
			continue;

		int mid_check = with_check[with_case[index_1][x]];

		if (mid_check)
		{
			with_check[with_case[index_1][x]] = 0;

			for (int y = index_1+1; y < stu_num; y++)
			{
				if (with_check[y]) {
					friend_count(y, real_1 + 2);
				}
			}

			with_check[with_case[index_1][x]] = 1;

			if (real_1 + 2 == stu_num)
				answer++;
		}
	}

	with_check[index_1] = 1;
	return 1;
}

int solution()
{
	int with_case_size; 
	answer = 0;
	cin >> stu_num >> with_case_size; 
	with_case.assign(stu_num, vector<int>(1, 0));
	with_check.assign(stu_num, 1);

	for (int x = 0; x < with_case_size; x++)
	{
		int start_0, end_0; cin >> start_0 >> end_0;

		if(start_0 <= end_0)
		 with_case[start_0].push_back(end_0);

		else
	     with_case[end_0].push_back(start_0);
	}

	friend_count(0,0);
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
