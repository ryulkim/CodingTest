#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool arr[11][12][5]={0,};//U R D L 순
    int x=5,y=5;
    
    for(int i=0;i<dirs.length();i++){
        if(dirs[i]=='U'){
            if(y-1>=0){
                if(arr[y-1][x][2]!=1){
                    answer+=1;
                    arr[y-1][x][2]=1;
                    arr[y][x][0]=1;
                }
                y--;
            }
        }
        else if(dirs[i]=='R'){
            if(x+1<=10){
                if(arr[y][x+1][3]!=1){
                    answer+=1;
                    arr[y][x+1][3]=1;
                    arr[y][x][1]=1;
                }
                x++;
            }
        }
        else if(dirs[i]=='D'){
            if(y+1<=10){
                if(arr[y+1][x][0]!=1){
                    answer+=1;
                    arr[y+1][x][0]=1;
                    arr[y][x][2]=1;
                }
                y++;
            }
        }
        else if(dirs[i]=='L'){
            if(x-1>=0){
                if(arr[y][x-1][1]!=1){
                    answer+=1;
                    arr[y][x-1][1]=1;
                    arr[y][x][3]=1;
                }
                x--;
            }
        }
    }
    return answer;
}
