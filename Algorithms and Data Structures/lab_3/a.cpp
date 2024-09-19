#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *head;

    List(){
        head = NULL;
    }

    void addNode(int num){
        Node *nd = new Node();
        nd->data = num;
        nd->next = head;
        head = nd;
    }
    int getNode(){
        int num;
        num = head->data;

        Node *node = head->next;
        head = node;

        return num;
    }
};

int main(){
    int n;
    cin >> n;
    int result[n];

    List list;

    char operation;
    int num;
    int j = -1;

    for (int i = 0; i < n; i++){
        cin >> operation;

        if (operation == '+'){
            cin >> num;
            list.addNode(num);
            
        } else {
            j++;
            result[j] = list.getNode();
        }
    }

    for (int i = 0; i <= j; i++){
        cout << result[i] << "\n";
    }
    return 0;
}