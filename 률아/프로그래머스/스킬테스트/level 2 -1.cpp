#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string word) {
        int answer = 0;
    string w = " AEIOU";
    string f = "AEIOU";
    for (char i : f) {
        for (char j : w) {
            for (char k : w) {
                if (j == ' ' && k != ' ')continue;
                for (char l : w) {
                    if (k == ' ' && l != ' ')continue;
                    for (char m : w) {
                        if (l == ' ' && m != ' ')continue;
                        answer += 1;
                        string s = "";
                        s.push_back(i);
                        if(j!=' ')s.push_back(j);
                        if (k != ' ')s.push_back(k);
                        if (l != ' ')s.push_back(l);
                        if (m != ' ')s.push_back(m);
                        
                        if (s == word) {
                            return answer;
                        }
                    }
                }
            }
        }
    }
    return answer;
}
