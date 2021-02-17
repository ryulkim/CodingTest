#include <string>
#include <vector>

using namespace std;

void dfs(int &answer, vector<int> numbers, int idx, int sum, int target, int size){
    if(idx==size-1){
        if(sum==target)answer++;
        return;
    }
    else{
        dfs(answer, numbers, idx+1, sum+numbers[idx+1],target, size);
        dfs(answer, numbers, idx+1, sum-numbers[idx+1],target, size);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(answer, numbers, 0, numbers[0], target, numbers.size() );
    dfs(answer, numbers, 0, -numbers[0], target, numbers.size() );
    return answer;
}
