#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    
    vector<int> data0;
    stringstream s0(s);
    string stringBuffer;
    
    while (getline(s0, stringBuffer, ' ')){
        data0.push_back(stoi(stringBuffer));
    }
 
    string answer = "";
                        
    answer = to_string(*min_element(data0.begin(),data0.end())) + " " + to_string(*max_element(data0.begin(),data0.end()));                                       
    return answer;
}
