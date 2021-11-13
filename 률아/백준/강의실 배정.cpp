#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>> pq;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int n, s, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        pq.push(make_pair(-s, -t));
    }

    priority_queue<int>v;
    v.push(pq.top().second);
    pq.pop();

    for (int j = 1; j < n; j++) {
        if (v.top() >= pq.top().first) {
            v.pop();
            v.push(pq.top().second);
            pq.pop();
        }
        else{
            v.push(pq.top().second);
            pq.pop();
        }
    }
    cout << v.size() << "\n";
}