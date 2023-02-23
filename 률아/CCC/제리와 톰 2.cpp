#include <iostream>
using namespace std;

int main(){
  int n, x;
  int arr[20]={0,};
  unsigned long long par, child, mod; //분모, 분자
  
  cin>>n;
  
  for(int i=0;i<n;i++){
    cin>>x;
    arr[i]=x;
  }

  par=1;
  child=arr[n-1];
  
  for(int i=n-2;i>=0;i--){
    long long temp=par;
    par=child;
    child=temp;
    
    child=arr[i]*par+child;
  }
  long long temp=par;
  par=child;
  child=temp;
  mod=par-child;
  
  cout<<mod<<' '<<par;
}
