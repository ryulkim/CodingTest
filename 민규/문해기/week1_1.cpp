#include <iostream>
#include <string>
#include <vector>
using namespace std;


string solution(int& n, string &data)
{
    vector<string> small_data;
    string returna = "";
    small_data.assign(n, "");

    for (int x = 0; x < n; x++) {
        int y = x;
        int y1 = n + (n - x-1);
        while (y < data.length()) {
            try {
                small_data[x].push_back(data[y]);
                y += 2*n;

                if (y1 < data.length())
                    small_data[x].push_back(data[y1]);

                else break;
                y1 += 2 * n;
 
            }

            catch (exception& e) {
                break;
            }
        }
    }
        
    for (int x = 0; x < n; x++) {
        //cout << small_data[x] << endl;
        returna += small_data[x];
    }

    return returna;
}


int main(void)
{
    int m,n;
    string data;

    cin >> m;

    for (int x = 0; x < m; x++)
    {
        cin >> data >> n;
        cout << solution(n, data);
        cout << "\n";
    }
    return 0;
}
