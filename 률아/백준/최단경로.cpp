#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int,int>
using namespace std;

int v, e, st;
const int INF = 1e9 + 10;

vector<pii> adj[20005];
int d[20005];
void dijkatra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[st] = 0;
	pq.push(make_pair(d[st], st));
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		int dist = cur.first, idx = cur.second;
		if (d[idx] != dist)continue;
		for (pii nxt : adj[idx]) {
			int cost = nxt.first, nidx = nxt.second;
			if (d[nidx] > dist + cost) {
				d[nidx] = dist + cost;
				pq.push(make_pair(d[nidx], nidx));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
	}
	dijkatra();
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}
}
