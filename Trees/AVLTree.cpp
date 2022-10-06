#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
    Node(int data, Node* parent = NULL){
        this->data = data;
        this->parent = parent;
    }

    Node(){};
};

class AVL{
    public:
    Node* root = NULL;

    void insert(int, Node*, Node*);
    void inorder(Node*);
    void right_rotate(Node *);
    void level_order();
};

void AVL:: insert(int data, Node* node, Node *parent = NULL){
    if (root == nullptr){
        root = new Node(data);
        return;
    }
    else if (node == NULL){
        if(parent->data < data) parent->right = new Node(data, parent);
        else parent->left = new Node(data, parent);
        return;
    }

    if(node->data < data) insert(data, node->right, node);
    else insert(data, node->left, node);
}

void AVL:: inorder(Node* node){
    if(node==nullptr) return;
    inorder(node->left);
    cout<<node->data<<' ';
    inorder(node->right);
}

void AVL:: right_rotate(Node * node){
    Node *left = node->left;
    
    node->left = left->right;
    left->right = node;
    left->parent = node->parent;
    node->parent = left;
    if(left->parent != nullptr) left->parent->left = left;
    else {
        root = left;
    }
}

void AVL::level_order(){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        if(root = nullptr) return;
        Node* node = q.front();
        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
        cout<<node->data<<' ';
        q.pop();
    }
} 

int main(){
    AVL tree;
    tree.insert(5, tree.root);
    tree.insert(8, tree.root);
    tree.insert(7, tree.root);
    tree.insert(4, tree.root);
    tree.insert(2, tree.root);
    tree.right_rotate(tree.root);
    tree.level_order();                                         

return 0;
}