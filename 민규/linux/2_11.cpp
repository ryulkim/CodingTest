#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<string> data0;

int room_num = 10;

int getoccupier()
{
 if(data0.size() >= room_num)
  return 0;

 else return data0.size();
}

int freeroom()
{
 if(!getoccupier())
  return 0;

 else data0.pop();
 return 1; 
}

int addguest(string data1)
{
 if(!getoccupier())
  return 0;

 else data0.push(data1);
 return 1; 
}

int findfree()
{
 if(!getoccupier())
  return 0;

 for(int x = getoccupier() ; x < room_num ; x++)
  cout << x << " ";
  
 cout << "\n";
 return 1;
}

int main(void)
{
 while(true){
 string name; cin >> name; if(name == "") break;
 if(freeroom()) cout << "guest checkout" << "\n";
 else cout << "no guest" << "\n";

 if(addguest(name))cout << "guest checkin" << "\n";
 else cout << "no room" << "\n";
 }

 return 0;
}
