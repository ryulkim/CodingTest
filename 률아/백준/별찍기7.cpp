#include <iostream>
using namespace std;

int n;

void d(int c, int sp, int st){
    if(c==0){
       return; 
    }
    for(int i=0;i<sp;i++){
        cout<<' ';
    }
    for(int i=0;i<st;i++){
        cout<<'*';
    }
    cout<<'\n';
    
    d(c-1,sp+1,st-2);
}

void u(int c, int sp, int st){
    
    for(int i=0;i<sp;i++){
        cout<<' ';
    }
    for(int i=0;i<st;i++){
        cout<<'*';
    }
    cout<<'\n';
    
    if(c==n){
       d(n-1,1,2*n-3);
       return; 
    }
    
    u(c+1,sp-1,st+2);
    
    
}



int main(){
    cin>>n;
    u(1,n-1,1);
}
