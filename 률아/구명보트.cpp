#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int light=0;
    int heavy=people.size()-1;
    while(heavy>light){
        if(people[light]+people[heavy]<=limit){
            light++;
        }
        heavy--;
        answer++;
    }
    if(heavy==light)answer++;
    return answer;
}
