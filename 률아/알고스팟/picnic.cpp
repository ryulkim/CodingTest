#include <iostream>
using namespace std;

int num = 0;
bool index[11] = { 0, };
int p;

void picnic(int arr[10][11], int n, int start) {
	if (n == 0) {
		num++;
		return;
	}
	for (int i = start; i < p; i++) {
		if (index[i] == 1) {
			continue;
		}
		index[i] = 1;
		for (int j = i+1; j < p; j++) {
			if (arr[i][j] == 0 || index[j] == 1) {
				continue;
			}
			index[j] = 1;
			picnic(arr, n-1, i+1);
			index[j] = 0;
		}
		index[i] = 0;
	}
	return;
}

int main() {
	int c, m, a, b;
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> p >> m;
		int arr[10][11] = { 0, };
		
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			arr[a][b] = 1;
			arr[b][a] = 1;
		}
		picnic(arr, p/2, 0);
		cout << num << '\n';
		num = 0;
		for (int j = 0; j < 10; j++) {
			index[j] = 0;
		}
	}
}
