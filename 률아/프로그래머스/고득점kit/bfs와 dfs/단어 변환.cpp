#include <string>
#include <vector>
#include <queue>

using namespace std;

bool graph[55][55]={0,};
bool check[55]={0,};
int taget_number=-1;

bool one_check(string a, string b) {
    int n = a.length();
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            num++;
        }
        if (num > 1) {
            return false;
        }
    }
    return true;
}

void create_graph(string begin, string target, vector<string> words) {
    int n = words.size();

    for (int i = 1; i <= n; i++) {
        if (one_check(begin, words[i - 1])) {
            graph[0][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (target == words[i - 1]) {
            taget_number = i;
        }
        for (int j = 1; j <= n; j++) {
            if (one_check(words[i - 1], words[j - 1])) {
                graph[i][j] = 1;
            }
        }
    }
}

int bfs(int n, vector<string> words, string target) {
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    int distance = 0;
    while (!q.empty()&&(q.front().first==0||words[q.front().first-1]!=target)) {
        int start = q.front().first;
        distance = q.front().second;
        for (int j = 0; j <= n; j++) {
            if (graph[start][j] == 1 && start != j && check[j] == 0) {
                check[j] = 1;
                q.push({ j,distance+1 });
            }
        }
        q.pop();
    }
    distance = q.front().second;
    return distance;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    create_graph(begin, target, words);
    if (taget_number == -1) {
        return 0;
    }
    answer = bfs(words.size(), words, target);
    return answer;
}
