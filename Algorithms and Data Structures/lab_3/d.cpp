#include <iostream>

using namespace std;

struct Node{
    long long data;
    Node *prev;
    Node *next; 
};

struct List{
    Node *head;
    Node *tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    void addNode(int data){
        Node *nd = new Node;
        nd->data = data;

        if (head == NULL && tail == NULL){
            nd->next = NULL;
            nd->prev = NULL;

            head = nd;
            tail = nd;
        } else if (tail == head) {
            nd->prev = tail;
            head->next = nd;

            head = nd;            
        } else {
            nd->prev = head;
            head->next = nd;

            head = nd;
        }
    }

    long long getFirstNode(){
        long long el = head->data;
        head->prev->next = NULL;
        head = head->prev;
        return el;
    }
    long long getLastNode(){
        long long el = tail->data;
        tail->next->prev = NULL;
        tail = tail->next;
        return el;
    }

};

int main(){
    int n, m;
    cin >> n >> m;

    List list;
    long long a, b, c, h;

    if (m >= n){
        int mas[n];
        
        for (int i = 0; i < n; i++){
            cin >> mas[i];
        }
        for (int i = 0; i < n; i++){
            cout << mas[i] << " ";
        }
        return 0;
    }

    for (int i = 0; i < m; i++){
        cin >> a;
        list.addNode(a);
    }

    for (int i = 0; i < n-m; i++){
        cin >> a;
        b = list.getFirstNode();
        c = list.getLastNode();

        if (a < b){
            h = a;
            a = b;
            b = h;
        }
        if (b < c){
            h = b;
            b = c;
            c = h;
        }
        if (a < b){
            h = a;
            a = b;
            b = h;
        }

        list.addNode(b);
        list.addNode(a);
    }

    long long el;
    Node *x = list.tail;
    while(x != NULL) {
        cout << x->data << " ";
        x = x->next;
    }
}