#include <iostream>

using namespace std;

struct Node{
    long long data;
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

    void push(long long data){
        Node *nd = new Node();
        nd->data = data;
        nd->next = head;
        head = nd;
    }
};

int main(){
    int n;
    cin >> n;

    long long lengths[n];
    for (int i = 0; i < n; i++){
        cin >> lengths[i];
    }

    int ls[n];
    int rs[n];
    Stack st;

    for (int i = 0; i < n; i++){
        while (!st.isEmpty() && lengths[st.head->data] >= lengths[i]){
            st.pop();
        }

        if (st.isEmpty()) {
            ls[i] = 0;
        } else {
            ls[i] = st.head->data + 1;
        }

        st.push(i);
    }

    while (!st.isEmpty()){
        st.pop();
    }

    for (int i = n-1; i >= 0; i--){
        while (!st.isEmpty() && lengths[st.head->data] >= lengths[i]){
            st.pop();
        }

        if (st.isEmpty()){
            rs[i] = n-1; 
        } else {
            rs[i] = st.head->data - 1;
        }

        st.push(i);
    }

    long long maxArea = 0;
    long long area;
    for (int i = 0; i < n; i++){
        area = lengths[i]*(rs[i] - ls[i] + 1);
        if (area > maxArea){
            maxArea = area;
        }
    }

    cout << maxArea;
    
    return 0;
}