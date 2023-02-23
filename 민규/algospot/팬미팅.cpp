#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string singer;
string fan;

void add(vector<int>& a, vector<int>& b,int k)
{
	for(int x = 0; x < b.size(); x++)
	{
		if (x + k < a.size())
			a[x + k] += b[x];


		else a.push_back(b[x]);	
	}
}


void sub(vector<int>& a, vector<int>& b)
{
	for (int x = 0; x < b.size(); x++)
	{
		a[x] -= b[x];
	}
}


vector<int> multiply(vector<int>& a, vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);

	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];

	return c;
}


vector<int> kara(vector<int>& a, vector<int>& b)
{
	int a_s = a.size(), b_s = b.size();

	if (a_s < b_s) return kara(b, a);

	if (a_s == 0 || b_s == 0)return vector<int>();
	if (a_s <= 100) return multiply(a, b);

	int half = a_s / 2;

	vector<int> a0(a.begin(), a.begin() + half), a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b_s,half)), b1(b.begin() + min<int>(b_s, half), b.end());

	vector<int> z2 = kara(a1, b1), z0 = kara(a0, b0);
	add(a0, a1, 0); add(b0, b1, 0);

	vector<int> z1 = kara(a0, b0);
	sub(z1, z0); sub(z1, z2);

	vector<int> ret;
	add(ret, z0, 0);
	add(ret, z1, half);
	add(ret, z2, half+half);
	return ret;
}


int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	for (int x = 0; x < n; x++) {
		cin >> singer >> fan;
		vector<int> singer_0; vector<int> fan_0;
		for (int x = 0; x < singer.size(); x++)singer_0.push_back(singer[x] == 'M');
		for (int x = fan.size()-1 ; x >= 0; x--)fan_0.push_back(fan[x] == 'M');
		vector<int>result_0 = kara(singer_0, fan_0);

		int answer = 0;
		for (int i = singer.size() - 1; i < fan.size(); ++i)
		{
			if (result_0[i] == 0)
				++answer;
		}

		cout << answer << "\n";	
	}

	return 0;
}
