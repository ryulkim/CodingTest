#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> forest;

int divide_conquer(int left, int right)
{
	if (left == right) return forest[left];

	int mid = (left + right) / 2;
	int ret = max(divide_conquer(left, mid), divide_conquer(mid + 1, right));

	int l1 = mid; int r1 = mid + 1;
	int height = min(forest[l1], forest[r1]);
	int span_count = 2;
	l1--; r1++;

	while ((left <= l1) || (right >= r1))
	{
		ret = max(ret, span_count * height);
		int forest_r = (right >= r1) ? forest[r1] : -1;
		int forest_l = (left <= l1) ? forest[l1] : -1;

		if (forest_l <= forest_r)
		{
			height = min(forest[r1], height); r1++;
		}

		else
		{
			height = min(forest[l1], height); l1--;
		}

		span_count++;
	}

	return max(ret, span_count * height);
}

int solution()
{
	forest.assign(0, 0);

	for (int x = 0; x < n; x++)
	{
		int data; cin >> data;
		forest.push_back(data);
	}

	return divide_conquer(0, n-1);
}


int main(void)
{
	int test_case; cin >> test_case;

	for (int x = 0; x < test_case; x++)
	{
		cin >> n;
		cout << solution() << "\n";
	}

	return 0;
}
