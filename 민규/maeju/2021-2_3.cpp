#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(),greater<int>());

    for(int x = 0 ; x < citations.size();x++)
      answer = max(answer,min(citations[x],x+1));
   
    return answer;
}
