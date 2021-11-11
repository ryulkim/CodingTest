#include <iostream>
#include <string>
#include <vector>

#define black true
#define red false

using namespace std;

class node_b
{
 public :
	node_b* parent = NULL;
	node_b* left =  NULL;
	node_b* right = NULL;
	int id; string name; int space, price;
	bool color = red; //true = black, false = red

	node_b(int i1, string n1, int s1, int p1, node_b* pa_index)
	{
		this->id = i1; this->name = n1;
		this->space = s1; this->price = p1; this->parent = pa_index;
	}

	void coloring(node_b* link)
	{
	
	   if (link->parent == NULL)
	   {
		   link->color = black;
		   return;
	   }

	   else if (link->parent->color == red)
	   {
		  node_b* un1 = uncle(link);
		  node_b* gra1 = grandparent(link);

		  if ((un1 != NULL) && (un1->color == red))
		  {
			  link->parent->color = black;
			  un1->color = black;
			  gra1->color = red;
			  coloring(gra1);
		  }

		  else
		  {
			  if ((link == link->parent->right) && (link->parent == gra1->left))
			  {
				  rotate_left(link->parent);
				  link = link->left;
		      }

			  else if ((link == link->parent->left) && (link->parent == gra1->right))
			  {
				  rotate_right(link->parent);
				  link = link->right;
			  }

			  gra1 = grandparent(link);
			  link->parent->color = black;
			  gra1->color = red;

			  if (link == link->parent->left)
				  rotate_right(gra1);

			  else
				  rotate_left(gra1);
		  }
	   }

	}

	void rotate_left(node_b* link)
	{
		node_b* right_l = link->right;
		node_b* parent_l = link->parent;

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

	void rotate_right(node_b* link)
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


	node_b* grandparent(node_b* link)
	{
		if (link->parent != NULL)
			return link->parent->parent;

		else return NULL;

	}
	
	node_b* uncle(node_b* link)
	{
		node_b* grand_a = this->grandparent(link);

		if (grand_a== NULL)
			return NULL;

		if (link->parent == grand_a->left)
			return grand_a->right;

		else return grand_a->left;
	}
};


class redblack
{
 public:
	int len = 0;
	node_b* tree_b;
	node_b* root;
	vector<node_b*> data0;


	void mode()
	{
	  string mode; cin >> mode;
	  int i1; string n1; int s1; int p1;

	  if (mode == "I")
	  {
		  
		  cin >> i1 >> n1 >> s1 >> p1;
		  insert(i1, n1, s1, p1);

		  while (root->parent != NULL)
			  root = root->parent;

		  //data0.pop_back(); data0.push_back(root);
		  //showing(data0);

		  cout << finding(i1, root, 0) << "\n";
	  }

	  else if (mode == "F")
	  {
		  cin >> i1;
		  cout << finding2(i1, root, 0) << "\n";
	  }

	  else if (mode == "R")
	  {
		  cin >> i1 >> n1 >> s1 >> p1;
		  cout << update(i1, root, 0,n1,s1,p1) << "\n";
	  }

	  else if (mode == "D")
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
			tree_b->coloring(tree_b);
			len++; root = tree_b;
			data0.push_back(root);
			return;
		}

		tree_b = root;
		while(true)
		{
			if (tree_b->id < i1)
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

			else if (tree_b->id > i1)
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

	int finding(int& data0, node_b* where0,int deepth)
	{
		if (data0 == where0->id)
			return deepth;

		else if (data0  < where0->id) //where0->left가 null일경우 error일 가능성 있음
			return finding(data0, where0->left, deepth + 1);

		else
			return finding(data0, where0->right, deepth + 1);

	}

	string finding2(int& data0, node_b* where0, int deepth)
	{
		if (data0 == where0->id)
			return to_string(deepth) + " " + where0->name + " " + to_string(where0->space) + " " + to_string(where0->price);

		else if (where0->left != NULL && data0 < where0->id)
			return finding2(data0, where0->left, deepth + 1);

		else if (where0->right != NULL && data0 > where0->id)
			return finding2(data0, where0->right, deepth + 1);

		else return "NULL";
	}


	string update(int& data0, node_b* where0, int deepth, string& n1, int& s1, int& p1)
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


	void discount(node_b* where0, int& min0, int& max0, int& discount0)
	{
		if (where0->id >= min0 && where0->id <= max0)
		{
		  where0->price = int(where0->price * (double(100 - discount0) / 100)); 
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
