#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    map<string, string> m1;
    cin >> n >> m;
    string s;
    string site, pass;
    for (int i = 0; i < n; i++) {
        cin >> site >> pass;
        m1.insert(pair<string, string>(site, pass));
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        cout << m1[s] << "\n";
    }
}
