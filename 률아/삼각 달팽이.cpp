#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int final = n * (n + 1) / 2;
    int arr[1002][1002] = { 0 };
    int fi = 0, fj = 0, li = n, lj = n;
    int direction = 2;
    int value = 1;
    while (value <= final) {
        if (direction == 2) {//down
            for (int i = fi; i < li; i++) {
                arr[i][fj] = value++;
            }
            direction = 6; fj++; fi++;
        }
        else if (direction == 6) {//right
            for (int j = fj; j < lj; j++) {
                arr[li - 1][j] = value++;
            }
            direction = 7; li--; lj--;
        }
        else if (direction == 7) {//left_up
            for (int i = li - 1, j = lj - 1; i >= fi, j >= fj; i--, j--) {
                arr[i][j] = value++;
            }
            direction = 2; fi++; lj--;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}
