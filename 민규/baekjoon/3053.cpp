#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
 int r; cin >> r; cout.precision(7); const double PI = acos(-1);
 printf("%.6f\n", (double)(r * r * PI)); printf("%.6f\n", (double)(r * r * 2));
 return 0;
}
