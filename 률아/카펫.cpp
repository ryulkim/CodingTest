#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int row, vertical;
    row=yellow;
    vertical=1;
    while(row>=vertical){
        if(yellow%vertical!=0){
            vertical++;
            continue;
        }
        else{
            row=yellow/vertical;
            if(brown==(row+vertical)*2+4){
            break;
            }
            else{
                vertical++;
            }
        }      
    }
    answer.push_back(row+2);
    answer.push_back(vertical+2);
    return answer;
}
