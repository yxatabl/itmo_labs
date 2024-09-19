#include <iostream>
#include <string>

using namespace std;

class BST{
    struct Node{
        string key;
        int size;
        Node* left;
        Node* right;

        Node(string data){
            key = data;
            left = right = nullptr;
            size = 0;
        }
    };

    int getSize(Node* p){
        return p ? p->size : 0;
    }

    void setSize(Node* p){
        if (p) p->size = getSize(p->left) + getSize(p->right) + 1; 
    }

    Node* insert(Node* root, string data){
        if (root == nullptr) root = new Node(data);
        else if (data < root->key) root->left = insert(root->left, data);
        else root->right = insert(root->right, data);

        setSize(root);
        return root;
    }

    string Kmax(Node* root, int k){
        if (!root) return "";

        int r = getSize(root->right);
        if (r == k-1) return root->key;
        if (r >= k) return Kmax(root->right, k);
        
        return Kmax(root->left, k - r - 1);
    }

    public:
    Node* root;

    BST(){
        root = nullptr;
    }

    void insert(string data){
        root = insert(root, data);
    }

    string Kmax(int k){
        return Kmax(root, k);
    }
};

int main(){
    BST bst = BST();
    int n, num, count = 0;
    string name;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> name;
        try{
            num = stoi(name);
            cout << bst.Kmax(count-num+1) << "\n";
        } catch (const exception& e){
            bst.insert(name);
            count++;
        }
    }
}