#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    char value;
    Node* left;
    Node* right;
};

class BTL {
public:
    Node* root;
    BTL(char r) {
        Node* node = new Node;
        node->value = r;
        node->left = NULL;
        node->right = NULL;
        root = node;
    }
    void insert(int n) {
        Node* node = new Node;
        char nd, l, r;

        for (int i = 0; i < n; i++) {
            cin >> nd >> l >> r;
            if (l != '.' || r != '.') {
                Node* par = search(nd);
                if (l != '.') {
                    Node* node = new Node;
                    node->value = l;
                    node->left = NULL;
                    node->right = NULL;
                    par->left = node;
                }
                if (r != '.') {
                    Node* node = new Node;
                    node->value = r;
                    node->left = NULL;
                    node->right = NULL;
                    par->right = node;
                }
            }
        }
    }
    Node* search(char value) {
        Node* node = root;
        queue<Node*> q;

        while (node->value != value) {
            if (node->left != NULL && node->left->value == value) {
                node = node->left;
            }
            else if (node->right != NULL && node->right->value == value) {
                node = node->right;
            }
            else {
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                node = q.front();
                q.pop();
            }
        }
        return node;
    }
    void pro(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->value;
        pro(node->left);
        pro(node->right);
    }
    void mid(Node* node) {
        if (node == NULL) {
            return;
        }
        mid(node->left);
        cout << node->value;
        mid(node->right);
    }
    void rear(Node* node) {
        if (node == NULL) {
            return;
        }
        rear(node->left);
        rear(node->right);
        cout << node->value;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    BTL b('A');
    b.insert(n); 
    b.pro(b.root);
    cout << '\n';
    b.mid(b.root);
    cout << '\n';
    b.rear(b.root);
    cout << '\n';
}
