#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int start = 1;
    int sum = 0;
    while (start != n) {
        for (int i = start; i < n; i++) {
            sum += i;
            if (sum == n) {
                answer++;
                sum = 0;
                break;
            }
            else if (sum > n) {
                sum = 0;
                break;
            }
        }
        start++;
    }

    return answer;
}
