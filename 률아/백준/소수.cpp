#include <iostream>
#include <cmath>
using namespace std;

int main() {
	unsigned int A, B, N;
	cin >> A >> B >> N;
	int m = A % B;
	int M;
	for (int i = 0; i < N; i++) {
		m *= 10;
		M = m / B;
		m %= B;
	}
	cout << M <<endl;
}
