#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int dp[301]={0,};
    vector<int> g;
    cin>>n;
    int grade;
    for(int i=0;i<n;i++){
        cin>>grade;
        g.push_back(grade);
    }
    dp[0]=g[0];
    dp[1]=g[0]+g[1];
    dp[2]=max(g[0]+g[2],g[1]+g[2]);
    for(int i=3;i<n;i++){
        int prev_one=g[i]+g[i-1]+dp[i-3];
        int prev_two=dp[i-2]+g[i];
        dp[i]=max(prev_one,prev_two);
    }
    cout<<dp[n-1];
}
