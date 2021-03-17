#include <iostream>
using namespace std;

int main() {
	int num;
	int a, b;
	bool ar[100][100] = { 0 };
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				ar[b - 1 + k][a - 1 + j]=true;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (ar[i][j] == true) {
				sum++;
			}
		}
	}
	cout << sum;
}
