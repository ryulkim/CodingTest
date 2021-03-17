#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, num;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end(),less<int>());
    for(int i=0;i<n;i++){
        cout<<v.at(i)<<endl;
    }
}
