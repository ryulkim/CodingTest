#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long a,b,c = 1000000007,d,e=1; long answer = 1;

long solution2(long a, long b)
{
 if(b <= 1) return a;
 else if(b%2) return (solution2((a*a)%c,b/2)*a)%c;
 else return (solution2((a*a)%c,b/2))%c;
}

long solution(long a0)
{
 if(a0 > a) return 1;
 answer = (a0 * answer)%c; e = (e*b)%c; b++;
 solution(a0+1);
 return 0;
}

int main(void)
{
 cin >> a >> b; d = max(b, a-b);b = 1;              
 solution(d+1); cout << (answer * solution2(e,c-2)%c)%c << "\n"; 
 return 0;
}
