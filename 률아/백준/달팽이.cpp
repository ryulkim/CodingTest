#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int n; int con = 1;
array <array <int, 100>, 100> s;
int a = 0, b = 0;

int main() {
	cin >> n;
	int ai = 0, af = n, bi = 0, bf = n;
	while (con<=n*n) {
		for (; b < bf; b++) {
			s[a][b] = con++;
		}
		b--; a++;
		ai++;
		for (; a < af; a++) {
			s[a][b] = con++;
		}
		a--; b--;
		bf--;
		for (; b >= bi; b--) {
			s[a][b] = con++;
		}
		b++; a--;
		af--;
		for (; a >= ai; a--) {
			s[a][b] = con++;
		}
		a++; b++;
		bi++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
}
