#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first, second, create=0;
    int size=scoville.size();
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<size;i++){
        q.push(scoville.at(i));
    }
    if(q.top()>=K){
        return answer;
    }
    while(q.size()>1&&q.top()<K){
        first=q.top();
        q.pop();
        second=q.top();
        q.pop();
        create=first+second*2;
        q.push(create);
        answer++;
    }
    if(q.top()<K){
        return -1;
    }
    return answer;
}
