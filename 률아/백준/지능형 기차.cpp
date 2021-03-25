#include <iostream>
using namespace std;

int main(){
    int num;
    int max=0;
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cin>>num;
            if(j==0){
                sum-=num;
            }
            else{
                sum+=num;
            }
            if(max<sum){
                max=sum;
            }
        }
    }
    cout<<max<<endl;
}
