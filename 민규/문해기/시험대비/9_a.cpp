#include <iostream>
#include <vector>
using namespace std;

int m_s;
vector<int> x_s_data;

long long find_num(int num_index)
{
 if(num_index <= 1)
  return x_s_data[num_index];

 else{
  long long alpa = find_num(num_index/2)%m_s;
  
  if(num_index%2)
   return (alpa * alpa * x_s_data[1])%m_s;

  return (alpa * alpa) % m_s;
 }
}


long long plus_num(int num_index)
{
 if(num_index <= 1) return x_s_data[num_index];

 long long next_plus = plus_num(num_index/2);

 if((num_index%2) == 0) //even
  return (next_plus +  (find_num(num_index/2) * next_plus)%m_s) % m_s;
 
 long long corr_odd = find_num(num_index/2+1); //odd
 return (next_plus + corr_odd +  (corr_odd*next_plus)%m_s) %m_s;  
}

int solution()
{
 int x_s,n_s; cin >> x_s >> n_s >> m_s;
 x_s_data.assign(2,0); 
 x_s_data[1] = x_s % m_s;

 long long answer = x_s_data[1];
 answer = plus_num(n_s); 
 return answer;
}

int main(void)
{
 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 int t_case; cin >> t_case;

 for(int x_t = 0 ; x_t < t_case ; x_t++)
 {
  cout << solution() << "\n";
 }

 return 0;
}
