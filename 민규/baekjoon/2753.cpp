#include <iostream>
using namespace std;


int main(void)
{
 int date;
 cin >> date;

 if(date%4 == 0 && date%100 > 0)
  cout << 1 << endl;

 else if(date % 400 == 0)
  cout << 1 << endl; 

 else cout << 0 << endl; 

 return 0;
}
