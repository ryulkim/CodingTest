#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one={1,2,3,4,5};
    vector<int> two={2,1,2,3,2,4,2,5};
    vector<int> three={3,3,1,1,2,2,4,4,5,5};
    
    int n=answers.size();    
    int one_p=0, two_p=0, three_p=0;
    int max=0;
    
    for(int i=0;i<n;i++){
        if(answers[i]==one[i%5]){
            one_p++;
            if(max<one_p){
                max=one_p;
            }
        }
        if(answers[i]==two[i%8]){
            two_p++;
            if(max<two_p){
                max=two_p;
            }
        }
        if(answers[i]==three[i%10]){
            three_p++;
            if(max<three_p){
                max=three_p;
            }
        }
    }
    
    if(one_p==max){
        answer.push_back(1);
    }
    if(two_p==max){
        answer.push_back(2);
    }
    if(three_p==max){
        answer.push_back(3);
    }
    
    return answer;
}
