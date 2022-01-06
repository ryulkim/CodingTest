#include <iostream>
using namespace std;

long long n0, m0, m1;
int n2 = 0;
int n5 = 0;
long long start0 = 0, end0 = 0;
long long five = 5, two = 2;

int solution(long long& num)
{	
	int alpa = (start0 % num != 0) ? 1 : 0;
	
	if (start0 < num) alpa = 1;
	else alpa += start0 / num;

	int beta = end0 / num;
	return beta - alpa + 1;
}

int main(void)
{
	cin >> n0 >> m0;

	m1 = min(m0,n0-m0); m0 = max(m0, n0 - m0);

	start0 = m0 + 1; end0 = n0;
	while (five <= end0 || two <= end0)
	{
		if (five <= end0) { n5 += solution(five); five *= 5;}
		if (two <= end0) { n2 += solution(two); two *= 2; }
	}

	five = 5; two = 2; start0 = 1; end0 = m1;
	while (five <= end0 || two <= end0)
	{
		if (five <= end0) { n5 -= solution(five); five *= 5; }
		if (two <= end0) { n2 -= solution(two); two *= 2; }
	}

	cout << min(n2,n5) << "\n";
	return 0;
}
