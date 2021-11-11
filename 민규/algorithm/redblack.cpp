#include <iostream>
#include <string>
#include <vector>

#define black true 
#define red false
using namespace std;

class node_b //tree를 이루는 point class , 해당 노드의 주소를 지금부터 p로 정의한다. 
{ 
 public :
	node_b* parent = NULL; //p의 부모 주소  
	node_b* left =  NULL; // p보다 작은 원소들의 트리 주소
	node_b* right = NULL; // p보다 큰 원소들의 트리 주소
	int id; string name; int space, price; //pdf에서 다루는 값들
	bool color = red; //true = black, false = red(default)

	node_b(int i1, string n1, int s1, int p1, node_b* pa_index) //node_b 초기화
	{
		this->id = i1; this->name = n1;
		this->space = s1; this->price = p1; this->parent = pa_index;
	}

	void coloring(node_b* link) //redblack 트리의 특성을 유지시켜주는 함수
	{
	
	   if (link->parent == NULL) //root 노드는 black이다.
	   {
		   link->color = black;
		   return;
	   }

	   else if (link->parent->color == red)
	   {
		  node_b* un1 = uncle(link); //uncle노드는 grandparent의 child중 현재 노드의 직속이 아닌 노드
		  node_b* gra1 = grandparent(link); //grandparent 노드는 parent->parent 노드

		  if ((un1 != NULL) && (un1->color == red)) //uncle 노드가 존재할 경우 parent색이 변동될 때, uncle도 반영해줄 코드가 필요하다
		  {											//같은 deepth이므로
			  link->parent->color = black;
			  un1->color = black;
			  gra1->color = red; //해당 코드 때문에 grandparent와 great-grandfather color가 에러가 생길 수 있다.
			  coloring(gra1); //따라서 재귀호출을 통해 color를 검사한다.
		  }

		  else //rotate하는 코드, uncle이 존재한 다는 것 현재 노드의 deep이 2이상 임을 의미한다.
		  {
			  if ((link == link->parent->right) && (link->parent == gra1->left)) //parent->id < gra->id && link->id > parent->id임을 의미한다.   
			  {//따라서 gra->id를 parent->left, link->id는 parent->right로 두어 구조를 단순화 시킬 수 있다.
				  rotate_left(link->parent);
				  link = link->left;
		      }

			  else if ((link == link->parent->left) && (link->parent == gra1->right)) //반대로 gra->id가 parent->right로 가게 된다.
			  {
				  rotate_right(link->parent);
				  link = link->right;
			  }

			  gra1 = grandparent(link); //가장 말단 노드가 red이므로
			  link->parent->color = black; //parent -> black
			  gra1->color = red;// grandparent -> red가 된다.

			  if (link == link->parent->left) //grandparent를 parent의 child로 만들어지면 자동으로 root 노드는 black이 된다.
				  rotate_right(gra1);

			  else
				  rotate_left(gra1);
		  }
	   }

	}

	void rotate_left(node_b* link) //grandparent를 parent의 left child로 만들어준다.
	{
		node_b* right_l = link->right; //삼입노드
		node_b* parent_l = link->parent; //parent링크를 인자로 전달 시 삽입 노드이 grandparent가 된다. 즉 이 노드를 옮기게 됨

		if (right_l->left != NULL)
			right_l->left->parent = link;

		link->right = right_l->left; link->parent = right_l;
		right_l->left = link; right_l->parent = parent_l;
		
		if (parent_l != NULL)
			if (parent_l->left == link)
				parent_l->left = right_l;

			else
				parent_l->right = right_l;
	}

	void rotate_right(node_b* link) //grandparent를 parent의 right child로 만들어준다.
	{
		node_b* left_l = link->left;
		node_b* parent_l = link->parent;

		if (left_l->right != NULL)
			left_l->right->parent = link;

		link->left = left_l->right; link->parent = left_l;
		left_l->right = link; left_l->parent = parent_l;

		if (parent_l != NULL)
			if (parent_l->right == link)
				parent_l->right = left_l;

			else
				parent_l->left = left_l;
	}


	node_b* grandparent(node_b* link)//grandparent구하기
	{
		if (link->parent != NULL)
			return link->parent->parent;

		else return NULL;

	}
	
	node_b* uncle(node_b* link)//uncle 구하기
	{
		node_b* grand_a = this->grandparent(link);

		if (grand_a== NULL)
			return NULL;

		if (link->parent == grand_a->left)
			return grand_a->right;

		else return grand_a->left;
	}
};


class redblack //node_b의 구조를 tree형태로 유지시킨다.
{
 public:
	int len = 0;
	node_b* tree_b;
	node_b* root; //root node
	vector<node_b*> data0;


	void mode()
	{
	  string mode; cin >> mode;
	  int i1; string n1; int s1; int p1;

	  if (mode == "I")
	  { 
		  cin >> i1 >> n1 >> s1 >> p1;
		  insert(i1, n1, s1, p1);

		  while (root->parent != NULL) //colorling으로 root노드 갱신될 수도 있으므로
			  root = root->parent;

		  //data0.pop_back(); data0.push_back(root);showing(data0);  //테스트 함수 deep 별로 데이터 현황을 파악 가능하다
		  
		  cout << finding(i1, root, 0) << "\n";
	  }

	  else if (mode == "F") //2. 탐색기능
	  {
		  cin >> i1;
		  cout << finding2(i1, root, 0) << "\n";
	  }

	  else if (mode == "R") //3. 업데이트 기능
	  {
		  cin >> i1 >> n1 >> s1 >> p1;
		  cout << update(i1, root, 0,n1,s1,p1) << "\n";
	  }

	  else if (mode == "D") //4. 할인 기능
	  {
		  int min0, max0, discount0; cin >> min0 >> max0 >> discount0;
		  discount(root, min0, max0, discount0);
	  }
	}

	void insert(int& i1, string& n1, int& s1, int& p1) //완전이진트리 -> 레드블랙트리
	{
		int depth = 0;
		
		if (len == 0) {
			tree_b = new node_b(i1,n1,s1,p1,NULL);
			tree_b->coloring(tree_b); //redblack 트리 구조 유지를 위해서 coloring(with rotate)를 해준다.
			len++; root = tree_b;
			data0.push_back(root); //갱신된 root 조합을 가지기 위해서
			return;
		}

		tree_b = root;
		while(true)
		{
			if (tree_b->id < i1) //child의 left 값들은 parent의 값보다 작다
			{
				if (tree_b->right == NULL)
				{
					tree_b->right = new node_b(i1, n1, s1, p1,tree_b);
					tree_b->right->coloring(tree_b->right);
					len++; return;
			    }

				else
				{
					tree_b = tree_b->right;
				}
			}

			else if (tree_b->id > i1) //child의 right 값들은 parent의 값보다 크다
			{
				if (tree_b->left == NULL)
				{
					tree_b->left = new node_b(i1, n1, s1, p1,tree_b);
					tree_b->left->coloring(tree_b->left);
					len++; return;
				}

				else
				{
					tree_b = tree_b->left;
				}
			}

			else {
			 return;
			}

		  depth++;
		}

	}

	int finding(int& data0, node_b* where0,int deepth) //deepth 출력을 하기 위해서
	{
		if (data0 == where0->id)
			return deepth;

		else if (data0  < where0->id) //where0->left가 null일경우 error일 가능성 있음, 단 현재 쓰임새에는 error수정 안해도 잘 돌아감
			return finding(data0, where0->left, deepth + 1);

		else
			return finding(data0, where0->right, deepth + 1);

	}

	string finding2(int& data0, node_b* where0, int deepth) //finding와 유사하나 error에 대비한 함수이다.
	{
		if (data0 == where0->id)
			return to_string(deepth) + " " + where0->name + " " + to_string(where0->space) + " " + to_string(where0->price);

		else if (where0->left != NULL && data0 < where0->id)
			return finding2(data0, where0->left, deepth + 1);

		else if (where0->right != NULL && data0 > where0->id)
			return finding2(data0, where0->right, deepth + 1);

		else return "NULL";
	}


	string update(int& data0, node_b* where0, int deepth, string& n1, int& s1, int& p1) //find함수와 유사하나 값 갱신하는 기능이 있음
	{
		if (data0 == where0->id) {
			where0->name = n1; where0->space = s1;
			where0->price = p1;
			return to_string(deepth);
		}
			 
		else if (where0->left != NULL && data0 < where0->id)
			return update(data0, where0->left, deepth + 1, n1,s1,p1);

		else if (where0->right != NULL && data0 > where0->id)
			return update(data0, where0->right, deepth + 1,n1, s1, p1);

		else return "NULL";
	}


	void discount(node_b* where0, int& min0, int& max0, int& discount0) //할인을 반영해준다.
	{
		if (where0->id >= min0 && where0->id <= max0)
		{
		  where0->price = int(where0->price * (double(100 - discount0) / 100)); //dobule로 캐스팅 안 해주면 0으로 반영되므로 주의
		}

		if (where0->left != NULL)
			discount(where0->left, min0, max0, discount0);

		if (where0->right != NULL)
			discount(where0->right, min0, max0, discount0);
	}

	void showing(vector<node_b*>& data00)
	{
	  vector<node_b*> data01;

	  for (auto x = data00.begin(); x != data00.end(); x++)
	  {
		  if ((*x) != NULL)
		  {
			  cout << (*x)->id << "+" << (*x)->color << " ";

			  if ((*x)->left != NULL)
				  data01.push_back((*x)->left);

			  if ((*x)->right != NULL)
				  data01.push_back((*x)->right);
	      }
	  }

	  cout << "\n";

	  if (data01.size())
		  showing(data01);
	}

};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	redblack alpa; 
	int all_case; cin >> all_case;

	for(int x = 0 ; x < all_case ; x++)
	{
		alpa.mode();
	}

	return 0;
}
