#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[50001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    fill(arr,arr+sizeof(arr)/sizeof(int),4);
    for(int i=1;i*i<=50000;i++){
        arr[i*i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sqrt(i);j++){
            arr[i]=min(arr[i],arr[i-j*j]+1);
        }
    }
    cout<<arr[n];
}
