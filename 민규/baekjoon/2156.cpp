#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp_bot;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int bottle = -1; dp_bot.assign(n, 0); int data;
	
	for (int x = 0; x < n; x++)
	{
		cin >> data; int y1,z1, z2, z3;

		y1 = (bottle >= 0) ? bottle: 0;
		z1 = (x >= 1) ? dp_bot[x - 1] : 0;
		z2 = (x >= 2) ? dp_bot[x - 2] : 0;
		z3 = (x >= 3) ? dp_bot[x - 3] : 0;

	    dp_bot[x] = max(max(data + y1 + z3, data + z2),z1);
		bottle = data;
	}

	cout << dp_bot.back() << "\n";
	return 0;
}
