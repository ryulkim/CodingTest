#include <iostream>
using namespace std;

void pibo(int n) {
	long long num0 = 0, num1 = 1, num2 = 1;
	for (int i = 0; i < n - 1; i++) {
		num2 = num0 + num1;
		num0 = num1; num1 = num2;
	}
	if (n == 0) cout<<0;
	else if(n == 1)cout<<1;
	else { cout << num2; }
}

int main() {
	int n;
	cin >> n;
	pibo(n);
}
