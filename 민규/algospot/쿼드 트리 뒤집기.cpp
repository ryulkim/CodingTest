#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ori_data;

string mapping_0(string::iterator& it)
{	
	char alpa = *(it++);

	if (alpa == 'x')
	{
		string upper_l = mapping_0(it); string upper_r = mapping_0(it);
		string lower_l = mapping_0(it); string lower_r = mapping_0(it);

		return string("x") + lower_l + lower_r + upper_l + upper_r;
	}

	else return string(1, alpa);
}

string solution()
{
	cin >> ori_data;  auto x = ori_data.begin();
    return mapping_0(x);
}


int main(void)
{
	int all_case; cin >> all_case;

	for (int x = 0; x < all_case; x++)
	{
		cout << solution() << "\n";
   	}

	return 0;
}
