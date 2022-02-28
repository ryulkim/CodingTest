#include <string>
#include <vector>
#include <queue>

using namespace std;

bool loc[205]={0,};

void bfs(vector<vector<int>> v, int fir, int n){
    queue<int> q;
    q.push(fir);
    loc[fir]=1;
    
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(int j=0;j<n;j++){
            if(i!=j&&v[i][j]==1&&loc[j]==0){
                q.push(j);
                loc[j]=1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(loc[i]==0){
            bfs(computers, i, n);
            answer++;
        }
    }
    return answer;
}
