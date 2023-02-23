#include <iostream>
#include <vector>
using namespace std;


int n = 0;
int m = 0;



class point
{
	public:
	point* parent = NULL;
	point* left = NULL;
	point* right = NULL;

	int key; int count;

	point(int key, int count)
	{
		this->key = key; this->count = count;
	}

};

int insert(point* for_a, int key,int mode)
{
	if (key < for_a->key)
	{
		if (for_a->left == NULL)
		{
			for_a->left = new point(key, 1); return -1;
		}

		else return insert(for_a->left, key, mode);
	}

	else if (key > for_a->key)
	{
		if (for_a->right == NULL)
		{
			for_a->right = new point(key, 1); return -1;
		}

		else return insert(for_a->right, key, mode);
	}

	else if(key == for_a->key){
		for_a->count += mode; return for_a->count;
	}

	return -2;
}

point* alpa;

int solution()
{
	vector<int> mess(m,0);
	vector <pair<int, int>> state;
	long long answer = 1;

	alpa = NULL;

	for (int x = 0; x < m; x++)
	{
		cin >> mess[x]; 
		
		if (x == 0) {
			alpa = new point(mess[x], 1);
		}

		else
		{
		  int d = insert(alpa, mess[x], 1);

		  if (d == -1) answer++;
		}

		//cout << answer << "\n";
	}

	for (int x = 0; x < m; x++)
	{
		cout << n - answer << "\n";

		int d = insert(alpa, mess[x], -1);
		if (d == 0) answer--;
	}

	return 0;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;

	for (int x = 0; x < t; x++)
	{
		cin >> n >> m; solution();
	}

	return 0;
}
