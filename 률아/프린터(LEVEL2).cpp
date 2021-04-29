#include <string>
#include <vector>

using namespace std;

class Node {
public:
    int locat;
    int prio;
    Node* next;

    Node(int loc, int p) {
        locat = loc;
        prio = p;
        next = NULL;
    }
};

class List {
public:
    Node* front;
    Node* end;
    int Size;

    List(int loc, int p) {
        Node* new_node = new Node(loc, p);
        front = new_node;
        end = new_node;
        Size = 1;
    }
    void add(int loc, int p) {
        Node* new_node = new Node(loc, p);
        end->next = new_node;
        end = new_node;
        Size++;
    }
    void erase() {
        front = front->next;
        Size--;
    }
    int size() {
        return Size;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    List l(0, priorities.at(0));
    for (int i = 1; i < priorities.size(); i++) {
        l.add(i, priorities.at(i));
    }
    int max = 0;
    for (int i = 0; i < priorities.size(); i++) {
        if (max < priorities.at(i)) {
            max = priorities.at(i);
        }
    }
    List f(0, 0);
    while (l.size()) {
        if (max > l.front->prio) {
            l.add(l.front->locat, l.front->prio);
            l.erase();
        }
        else if (max == l.front->prio) {
            f.add(l.front->locat, l.front->prio);
            l.erase();
            max = 0;
            if (l.size()) {
                Node* cur_node = l.front;
                while (cur_node->next != NULL) {
                    if (max < cur_node->prio) {
                        max = cur_node->prio;
                    }
                    cur_node = cur_node->next;
                }
                if (max < cur_node->prio) {
                    max = cur_node->prio;
                }
            }
        }
    }
    Node* cur_node = f.front->next;
    while (cur_node->next!=NULL) {
        answer++;
        if (cur_node->locat == location) {
            return answer;
        }
        cur_node = cur_node->next;
    }
    answer++;
    return answer;
}
