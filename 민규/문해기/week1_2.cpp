#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


vector<int> block;
int min0 = 1001;
int max0 = 0;
string solution(string &data)
{
    try {
        
        
        if (data == "return") {
            min0 = 0;
            max0 = 0;
            block.resize(0);
        }

        else
        {
            if (data[0] == 'B')
            {
             if(!block.empty()){
                block.pop_back();
                min0 = *min_element(block.begin(), block.end());
                max0 = *max_element(block.begin(), block.end());
             }
                return "blank";
            }

            else{
                int value_a = stoi(data);
        
                if (block.empty())
                {
                    min0 = value_a;
                    max0 = value_a;
                }

                else {
                    min0 = (min0 > value_a) ? value_a : min0;
                    max0 = (max0 < value_a) ? value_a : max0;
                }

                block.push_back(value_a);
            }
        }

        if (block.empty())
            return "blank";

        //cout << block.size() << endl;
        return to_string(min0) + " " + to_string(max0);
    }

    catch (exception& e)
    {
        cout << e.what() << endl;
        //cout << data << endl;
    }

    return "";
}


int main(void)
{
    int m,n;
    string data;

    cin >> m;

    for (int x = 0; x < m; x++)
    {
        cin  >> n;
        string data = "return";
        solution(data);
        for (int y = 0; y < n; y++)
        {
            cin >> data;
            
            if (data == "1")
                cin >> data;

            else
                data = "B";

            //cout << data << endl;
            string final = solution(data);

            if (final != "blank")
            {
                cout << final;
                cout << "\n";
            }
        }
    }
    return 0;
}
