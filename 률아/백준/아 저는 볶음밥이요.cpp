#include <iostream>
using namespace std;

int main(){
  long long int n,m,k,d,bok=0,temp_gun, temp_bok;
  long long int max=0, gun=0;
  cin>>d>>n>>m>>k;
  
  long long int n_fill=d-(n-(n/d)*d);
  long long int m_fill=d-(m-(m/d)*d);

  gun+=n/d;
  gun+=m/d;
  
  //짜장, 짬뽕을 채울 때
  temp_bok=k-n_fill-m_fill;
  if(temp_bok>=0){
    temp_gun=gun+2+(temp_bok/d);
    if(temp_gun>=max){
      max=temp_gun;
      bok=temp_bok;
      }
    }
  //짜장만 채울 때
  temp_bok=k-n_fill;
  if(temp_bok>=0){
    temp_gun=gun+1+(temp_bok/d);
    if(temp_gun>max){
      max=temp_gun;
      bok=temp_bok;
    }
     else if(temp_gun==max&&temp_bok>bok){
      max=temp_gun;
      bok=temp_bok;
     }
  }
  //짬뽕만 채울 때
  temp_bok=k-m_fill;
  if(temp_bok>=0){
    temp_gun=gun+1+(temp_bok/d);
    if(temp_gun>max){
      max=temp_gun;
      bok=temp_bok;
    }
     else if(temp_gun==max&&temp_bok>bok){
      max=temp_gun;
      bok=temp_bok;
     }
  }
  //다 안 채울 때
  temp_bok=k;
  temp_gun=gun+(temp_bok/d);
  if(temp_gun>max){
      max=temp_gun;
      bok=temp_bok;
    }
    else if(temp_gun==max&&temp_bok>bok){
        max=temp_gun;
        bok=temp_bok;
    }

  cout<<bok<<'\n';
}
