#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    vector<int>arr(n);
    int answer = 0;
    for(int i=2;i<n-1;i++){
        if(arr.at(i-2)==0){
            for(int j=i*2;j<=n;j+=i){
                arr.at(j-2)=1;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(arr.at(i)==0){
            answer++;
        }
    }
    return answer;
}
