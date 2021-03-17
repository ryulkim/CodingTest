#include <iostream>
using namespace std;

int main()
{
    char arr[1000001] = { 48, };
    unsigned int sum = 0, count = 0, check = 0, num = 1111;
    cin >> arr;
    for (unsigned int i = 0; i < 1000000; i++) {
        if (arr[i] != NULL) {
            sum += (static_cast <int>(arr[i]) - '0'); 
            check++;
        }
        arr[i] = '0';
    }
    num = sum; sum = 0;
    if (check > 1)count++;
    while (!((num / 10) == 0)) {
        for (unsigned int i = 0; i < 1000001; i++) {
            sum += num % 10; num /= 10;
        }
        count++; num = sum;
        sum = 0;
    }
    cout << count << endl;
    if (num % 3 == 0)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
