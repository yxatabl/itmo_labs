#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class bst{
    struct Node{
        T key;
        Node* left;
        Node* right;

        Node(T data){
            key = data;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root = nullptr;

    Node* insert(Node* root, T data){
        if (root == nullptr) return new Node(data);
        
        if (data > root->key) root->right = insert(root->right, data);
        else if (data < root->key) root->left = insert(root->left, data);

        return root;
    }

    Node* minNode(Node* root){
        while (root->left != nullptr) root = root->left;
        return root;
    }

    Node* remove(Node* root, T key){
        if (root == nullptr) return root;

        if (key > root->key) root->right = remove(root->right, key);
        else if (key < root->key) root->left = remove(root->left, key);
        else {
            if (root->left == nullptr && root->right == nullptr) return nullptr;
            else if (root->left == nullptr) return root->right;
            else if (root->right == nullptr) return root->left;
            else {
                Node* temp = minNode(root->right);
                root->key = temp->key;
                root->right = remove(root->right, temp->key);
            }
        }

        return root;
    }

    Node* search(Node* root, T key){
        if (root == nullptr) return nullptr;
        if (root->key == key) return root;
        if (key > root->key) return search(root->right, key);
        if (key < root->key) return search(root->left, key);
    }

    public:
    void push(T data){
        root = insert(root, data);
    }

    void pop(T key){
        root = remove(root, key);
    }

    bool exists(T key){
        return search(root, key) != nullptr;
    }
};

int main(){
    int n;
    string el;
    bst<string> stAb, stBb, stCb;
    vector<string> stAv, stBv, stCv;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> el;
        stAb.push(el);
        stAv.push_back(el);
    }
    for (int i = 0; i < n; i++){
        cin >> el;
        stBb.push(el);
        stBv.push_back(el);
    }
    for (int i = 0; i < n; i++){
        cin >> el;
        stCb.push(el);
        stCv.push_back(el);
    }

    int sum = 0;
    int ind;
    for (int i = 0; i < n; i++){
        el = stAv[i];
        ind = stBb.exists(el) + stCb.exists(el);
        switch (ind){
            case 0:
                sum += 3;
                break;
            case 1:
                sum += 1;
                break;
        }
    }
    cout << sum << " ";

    sum = 0;
    for (int i = 0; i < n; i++){
        el = stBv[i];
        ind = stAb.exists(el) + stCb.exists(el);
        switch (ind){
            case 0:
                sum += 3;
                break;
            case 1:
                sum += 1;
                break;
        }
    }
    cout << sum << " ";

    sum = 0;
    for (int i = 0; i < n; i++){
        el = stCv[i];
        ind = stAb.exists(el) + stBb.exists(el);
        switch (ind){
            case 0:
                sum += 3;
                break;
            case 1:
                sum += 1;
                break;
        }
    }
    cout << sum;
}