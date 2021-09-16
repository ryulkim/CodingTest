#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> data0;

long long sum(std::vector<int> &a)
{
 return accumulate(a.begin(), a.end(), 0ll);
}
