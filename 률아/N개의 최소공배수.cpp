#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int check[102] = { 0, };
    int answer = 1;
    int j = 2;
    
    int n;
    for (int i = 0; i < arr.size(); i++) {
        n = arr[i];
        int jisu = 0;
        while (n != 1) {
            if (n % j==0) {
                n /= j;
                jisu++;
            }
            else {
                if (check[j] < jisu) {
                    check[j] = jisu;
                }
                j++;
                jisu = 0;
            }
        }
        if (check[j] < jisu) {
            check[j] = jisu;
        }
        jisu = 0;
        j = 2;
    }
    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j < check[i]; j++) {
            answer *= i;
        }
    }
    return answer;
}
