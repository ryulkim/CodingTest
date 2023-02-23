#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
};

class BTL {
public:
    Node* root;
    BTL(int r) {
        Node* node = new Node;
        node->value = r;
        node->left = NULL;
        node->right = NULL;
        root = node;
    }
    void insert(int value) {
        Node* node = new Node;
        Node* guide = root;
        Node* par = root;

        node->value = value;
        node->left = NULL;
        node->right = NULL;

        while (guide != NULL) {
            if (value < guide->value) {
                par = guide;
                guide = guide->left;
            }
            else {
                par = guide;
                guide = guide->right;
            }
        }
        if (value < (par->value)) {
            par->left = node;
        }
        else {
            par->right = node;
        }
    }
    void rear(Node* node) {
        if (node == NULL) {
            return;
        }
        rear(node->left);
        rear(node->right);
        cout << node->value << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, n;
    cin >> r;
    BTL b(r);
    while (cin >> n) {
        b.insert(n);
    }
    b.rear(b.root);
}
