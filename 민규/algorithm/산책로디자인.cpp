#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph_p;
vector<vector<int>> graph_n;
vector<int> list_w;
const int inf = 20000; //산책로 디자인 비용(10~10000)은 20000을 넘지 않습니다
int size_0; //point 종류의 수


void coloring(vector<int>& case_list, int start_0) //현 point 상황을 반영, start_0과 다른 point간의 관계(최솟값)을 표시                                 
{
	for (auto x = ++graph_n[start_0].begin(); x != graph_n[start_0].end(); x++)
	{
		case_list[*x] = min(case_list[*x], graph_p[start_0][*x]); //만약 -1일 시에는 새롭게 추가된 경로가 발현되어도 -1보다 작지 않으므로 지나간 상태유지
	}

	case_list[start_0] = -1;
}

int prim(int start, int result, vector<int>& case_list)
{
	if (list_w.size() >= size_0) return result; //list_w의 사이즈가 size_0(graph의 point의 종류의 수) 이상일 시, 모든 포인트를 모은 것입니다.

	int next_index = inf; int next_value = inf;
	auto x = ++case_list.begin(); //start in 1 not 0, vector의 index는 0에서 시작하나 해당문제의 index는 1에서 부터 시작합니다

	for (1; x != case_list.end(); x++)
	{
		if (*x < inf && *x > 0) //inf일 시는 현 상황에서 지나가지 않는 point, -1일 시에는 이미 지나간 point
		{
			int x1 = (int)(x - case_list.begin());

			if (next_value > *x) {} //case1 : 현재까지 찾은 index 중에서 가장 작은 가중치를 가짐
			else if (next_value == *x && x1 < next_index) {} //case2 : 현재까지 찾은 index 중에서 동일한 가중치를 가짐 + 가장 작은 index 값 
			else continue;
		
			next_value = *x;
			next_index = x1;
		}
	}

	coloring(case_list, next_index);//해당 함수를 마치면서 지나간 point는 다시 coloring을 해줍니다
	list_w.push_back(next_index);
	return prim(next_index, result + next_value, case_list);
}

int solution(int start_0)
{
	list_w.assign(1, start_0); vector<int> case_list; //list_w는 거처간 point의 index 값을 저장할 것 입니다
	case_list.assign(size_0 + 1, inf);// case_list는 현 상황에서의 point의 상태를 담고 있으며 [inf : 아직 지나가지 않음 , -1 : 지나감]을 의미
	coloring(case_list, start_0); 
	cout << prim(start_0,0,case_list) << " "; //산책로 디자인 비용의 합을 return할 prim 함수 설계

	for (auto x = list_w.begin(); x != list_w.end(); x++)
		cout << *x << " ";

	cout << "\n";
	return 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> size_0; 
	graph_p.assign(size_0 + 1, vector<int>(size_0 + 1 , 0)); //weight 저장, 무향 그래프 반영
	graph_n.assign(size_0 + 1, vector<int>(1, 0)); // point 간 관계 저장
	
	int make_g, comm_g; cin >> make_g >> comm_g;
	
	for (int x = 0; x < make_g; x++)
	{
		int x1, y1, weight1; cin >> x1 >> y1 >> weight1;
		graph_p[x1][y1] = weight1; graph_p[y1][x1] = weight1; //(x1,y1) , (y1,x1)의 weight를 저장합니다. o(1)에 접근 가능하도록                
		graph_n[x1].push_back(y1); graph_n[y1].push_back(x1); // a번째에 연결된 point의 값을 저장합니다. 최대 n	
	}

	for (int x = 0; x < comm_g; x++)
	{
		char mode; int start_0; cin >> mode >> start_0;
		if(mode == 'P')
		 solution(start_0);
	}

	return 0;
}
