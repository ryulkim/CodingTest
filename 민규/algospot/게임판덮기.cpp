#include <iostream>
#include <vector>
using namespace std;

const vector<vector<vector<int>>> ty_a = { 
	{ {0,0}, {1,0}, {0,1} },
	{ {0,0}, {0,1}, {1,1}},
	{ {0,0}, {1,0}, {1,1} },
	{ {0,0}, {1,0}, {1,-1}}
};

int answer = 0;
vector<vector<bool>> map_0;
int cover_0();
int w, h;

int cover_1(int& x0, int& y0,int w0,int data)
{
  if (data > 0)
	for (int x = 0; x < 3; x++)
	{ 
		int c_x = x0 + ty_a[w0][x][0], c_y = y0 + ty_a[w0][x][1];

		if (c_x < 0 || c_x >= w) return 0;
		if (c_y < 0 || c_y >= h) return 0;

		if (map_0[c_x][c_y] + 1 >= 2) return 0;		
	}

  for (int x = 0; x < 3; x++)
  {
	  int c_x = x0 + ty_a[w0][x][0], c_y = y0 + ty_a[w0][x][1];
	  map_0[c_x][c_y] = map_0[c_x][c_y] + 1 * data;
  }
  
	return 1;
}


int cover_0()
{
	int x = -1, y = -1;
	for (x = 0; x < w; x++)
	{
		for (y = 0; y < h;y++)
		{
			if (map_0[x][y] == 0)
				goto loop1;
		}
	}

	answer++; return 0;
	loop1:;

	for (int w = 0; w < 4; w++) {

		if (cover_1(x, y, w, 1))
		{ 
		  cover_0();
		  cover_1(x, y, w, -1);
		}
	}

	return 1;
}


int solution()
{
	map_0.assign(w,vector<bool>(h,0));
	answer = 0; int l_count = 0;

	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			char mark; cin >> mark;

			if (mark == '#')
				map_0[x][y] = 1;

			else l_count++;
		}
	} //making_map 1 = white, 0 = black

		 
	if (l_count % 3 != 0)
		return 0;

	else l_count = l_count / 3;
	
	cover_0();
	return answer;
}

int main(void)
{
	int all_case; cin >> all_case;

	for (int x = 0; x < all_case; x++)
	{
		cin >> w >> h;
		cout << solution() << "\n";
	}
	return 0;
}
