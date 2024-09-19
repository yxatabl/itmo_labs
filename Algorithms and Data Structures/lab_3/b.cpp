#include <iostream>

using namespace std;

struct Node{
    long long data;
    Node *next;
};

class List{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void addNode(long long d)
    {
        Node *nd = new Node;

        nd->data = d;
        nd->next = NULL;

        if (head == NULL){
            head = nd;
            tail = nd;
        } else {
            tail->next = nd;
            tail = nd;
        }
    }

    long long getNode(){
        long long num = head->data;
        head = head->next;
        return num;
    }
};

int main(){
    List myList;

    int n;
    cin >> n;

    char operation;
    long long num;
    long long res[n];
    int j = -1;

    for (int i = 0; i < n; i++){
        cin >> operation;

        if (operation == '+'){
            cin >> num;
            myList.addNode(num);
        } else {
            j++;
            num = myList.getNode();
            res[j] = num;
        }
    }

    for (int i = 0; i <= j; i++){
        cout << res[i] << "\n";
    }

    return 0;
}