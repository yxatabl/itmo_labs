#include <iostream>
#include <string>

using namespace std;

class BST{
    struct Node{
        long long key;
        int size;
        Node* left;
        Node* right;

        Node(long long data){
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

    Node* insert(Node* root, long long data){
        if (root == nullptr) root = new Node(data);
        else if (data < root->key) root->left = insert(root->left, data);
        else if (data > root->key) root->right = insert(root->right, data);

        setSize(root);
        return root;
    }

    Node* findMin(Node* root){
        while (root->left != nullptr) root = root->left;
        return root;
    }

    Node* remove(Node* root, long long key){
        if (!root) return root;

        if (key < root->key) root->left = remove(root->left, key);
        else if (key > root->key) root->right = remove(root->right, key);
        else {
            if (root->left == nullptr && root->right == nullptr){
                root = nullptr;
            }
            else if (root->left == nullptr) root = root->right;
            else if (root->right == nullptr) root = root->left;
            else {
                Node* nd = findMin(root->right);
                root->key = nd->key;
                root->right = remove(root->right, nd->key);
            }
        }

        setSize(root);
        return root;
    }

    long long Kmax(Node* root, long long k){
        if (!root) return -1;

        long long r = getSize(root->right);
        if (r == k-1) return root->key;
        if (r >= k) return Kmax(root->right, k);
        
        return Kmax(root->left, k - r - 1);
    }

    public:
    Node* root;

    BST(){
        root = nullptr;
    }

    void insert(long long data){
        root = insert(root, data);
    }

    long long Kmax(long long k){
        return Kmax(root, k);
    }

    void remove(long long key){
        root = remove(root, key);
    }
};

int main(){
    BST bst = BST();
    int n, command, k;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> command >> k;
        if (command == 1){
            bst.insert(k);
        } else if (command == 0){
            cout << bst.Kmax(k) << "\n";
        } else if (command == -1){
            bst.remove(k);
        }
    }

    return 0;
}