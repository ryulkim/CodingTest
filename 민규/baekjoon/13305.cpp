#include <iostream>
#include <vector>
using namespace std;

int n;

vector<int> distanse;
int oil_value;
int max_distnase = 0;


int main(void)
{
	cin >> n; 
	distanse.assign(n - 1, 0);

	for (int x = 0; x < n - 1; x++)
	{
		cin >> distanse[x]; max_distnase += distanse[x];
	}

	int current_oil = 0;
	long answer = 0;
	
	for (int x = 0; x < n-1; x++)
	{
		cin >> oil_value;  
		
		if (x == 0) current_oil = oil_value;
		else current_oil = min(oil_value, current_oil);
		
		answer += (long)(current_oil) * (long)(distanse[x]);
	}

	cout << answer << "\n";
	return 0;
}








