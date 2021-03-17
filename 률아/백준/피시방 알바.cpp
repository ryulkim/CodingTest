#include <iostream>
#include <array>
using namespace std;
array<int, 100> b;

void line(array<int,100> a,int n) {
	int sum = 0;
	for (int i = 0; i < n;i++) {
		if (b[a[i]] == 1)sum += 1;
		else b[a[i]] = 1;
	}
	cout << sum;
}

int main() {
	int n;
	cin >> n;
	array<int, 100>a;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	line(a, n);
}
