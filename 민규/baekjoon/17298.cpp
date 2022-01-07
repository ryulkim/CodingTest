#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> ori;
stack<int> where0;
vector<int> update;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	ori.assign(n, 0);  update.assign(n, -1); 
	int check_index = 0;

	for (int x = 0; x < n; x++)
	{
		cin >> ori[x];

		while(where0.size() > 0 && ori[where0.top()] < ori[x])
		{
			update[where0.top()] = ori[x];
			where0.pop();
		}

		where0.push(x);
	}

	for (int x = 0; x < n; x++)
		cout << update[x] << " ";

	cout << "\n";
	return 0;
}
