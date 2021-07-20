#include <vector>

using namespace std;

int size_of_one_area=0;

void dfs(int i, int j, int color_num, vector<vector<int>> &picture){
    if (picture[i][j] == color_num) {
        size_of_one_area++;
        picture[i][j] = 0;
    }
    if (i < picture.size() - 1 && picture[i + 1][j] == color_num) {
        dfs(i + 1, j, color_num, picture);
    }
    if (j < picture[0].size() - 1 && picture[i][j + 1] == color_num) {
        dfs(i, j + 1, color_num, picture);
    }
    if (i > 0 && picture[i - 1][j] == color_num) {
        dfs(i - 1, j, color_num, picture);
    }
    if (j > 0 && picture[i][j - 1] == color_num) {
        dfs(i, j - 1, color_num, picture);
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<int>> copy = picture;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(copy[i][j]==0)continue;
            dfs(i,j, copy[i][j], copy);
            if(max_size_of_one_area<size_of_one_area){
                max_size_of_one_area=size_of_one_area;
            }
            size_of_one_area=0;
            number_of_area++;
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
