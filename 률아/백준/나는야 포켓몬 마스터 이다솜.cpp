#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, a;
    cin >> m >> n;
    string s;
    map<string, int> m1;
    vector<string> v;
    for (int i = 0; i < m; i++) {
        cin >> s;
        m1.insert(pair<string, int>(s, i));
        v.push_back(s);
    }
    for (int j = 0; j < n; j++) {
        cin >> s;
        if (isdigit(s[0])) {
            stringstream ss(s);
            ss >> a;
            cout << v.at(a-1) << "\n";
            
        }
        else {//숫자 출력
            cout << m1[s]+1<< "\n";
        }
    }
}
