#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
using namespace std;

int bfs(int str, int des) {
    queue<pair<int, int>> q;//first: 횟수, second: 값
    q.push(make_pair(1, str));

    int v;
    string s;

    while (!q.empty()&&q.front().second != des) {
        s = to_string(q.front().second) + '1';
        try {
            v = stoi(s);
            if (v <= des) {
                q.push(make_pair(q.front().first + 1, v));
            }
        }
        catch (const std::exception& expn) {
            
        }
        if (q.front().second * 2 <= des) {
            q.push(make_pair(q.front().first + 1, q.front().second * 2));
        }
        q.pop();
    }

    return q.empty() ? -1: q.front().first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int str, des;
    cin >> str >> des;
    
    cout << bfs(str, des) << '\n';
}
