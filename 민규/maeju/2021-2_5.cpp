#include <string>
#include <vector>

using namespace std;
const int mod = 1234567;

int solution(int n) {
    int answer = 0;
    vector<int> data1(100001,0);
    data1[0] = 0; data1[1] = 1;

    for(int x = 2; x <= n;x++)
    {
     data1[x] = (data1[x-1] + data1[x-2])%mod;
    }

    return data1[n];
}
