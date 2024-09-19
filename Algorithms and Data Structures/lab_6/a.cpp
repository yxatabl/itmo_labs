#include <iostream>

using namespace std;

struct Node{
    long long key;
    Node* left;
    Node* right;
    int height;

    Node(long long num){
        key = num;
        height = -1;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* nd){
    if (nd == nullptr) return -1;
    if (nd->height != -1) return nd->height;
    int hl = height(nd->left);
    int hr = height(nd->right);
    int h = hl > hr ? hl+1 : hr+1;
    nd->height = h;
    return h;
}

int main(){
    int n;
    cin >> n;

    Node* list[n];
    for (int i = 0; i < n; i++) list[i] = new Node(0);

    long long k, l, r;
    for (int i = 0; i < n; i++){
        cin >> k >> l >> r;
        list[i]->key = k;
        if (l > 0) list[i]->left = list[l-1];
        if (r > 0) list[i]->right = list[r-1];
    }

    for (int i = 0; i < n; i++){
        cout << height(list[i]->right)-height(list[i]->left) << "\n";
    }
}