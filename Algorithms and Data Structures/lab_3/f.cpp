#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Stack{
    Node *head;

    Stack(){
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr; 
    }

    void pop(){
        head = head->next;
    }

    void push(int data){
        Node *nd = new Node();
        nd->data = data;
        nd->next = head;
        head = nd;
    }
};

int main() {
    int n;
    cin >> n;

    int tasks[n];
    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }

    int days[n];
    Stack s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.isEmpty() && tasks[i] >= tasks[s.head->data]) {
            s.pop();
        }
        if (s.isEmpty()) {
            days[i] = -1;
        } else {
            days[i] = s.head->data - i;
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << days[i] << " ";
    }
    return 0;
}