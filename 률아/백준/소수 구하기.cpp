#include <iostream>
using namespace std;

bool arr[1000005]={0,};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    int m,n;
    cin>>m>>n;
    arr[0]=1;
    arr[1]=1;
    
    for(int i=2;i<=n;i++){
        if(arr[i])continue;
        for(int j=2*i;j<=n;j+=i){
            if(!arr[j]){
                arr[j]=1;
            }
        }
    }
    for(int i=m;i<=n;i++){
        if(!arr[i]){
            cout<<i<<'\n';
        }
    }
}
