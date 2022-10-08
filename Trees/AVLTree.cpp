#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data, height = 1;
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
    Node(int data, Node* parent = NULL){
        this->data = data;
        this->parent = parent;
    }

    Node(){};

    int heightbalance(){
        int left_height = (left != nullptr)? left->height : 0;
        int right_height = (right != nullptr)? right->height : 0;
        return left_height - right_height;
    }
};

class AVL{
    public:
    Node* root = NULL;

    void insert(int, Node*, Node*);
    void inorder(Node*);
    void level_order();
    void right_rotate(Node*);
    void left_rotate(Node*);
};


void AVL:: inorder(Node* node){
    if(node==nullptr) return;
    inorder(node->left);
    cout<<node->data<<' ';
    inorder(node->right);
}

void AVL::level_order(){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
        cout<<node->data<<' ';
        q.pop();
    }
    cout<<endl;
}

int height(Node* node){
    if(node == nullptr) return 0;
    return node->height;
}

void AVL:: right_rotate(Node * node){
    Node *left = node->left;
    
    node->left = left->right;
    left->right = node;
    if(node->left != nullptr) node->left->parent = node;
    
    left->parent = node->parent;
    node->parent = left;
    node->height = 1+max(height(node->left), height(node->right));
    left->height = 1+max(height(left->left), height(left->right));
    
    if(left->parent == nullptr) root = left;
    else {
        Node* parent = left->parent;
        if(parent->left == node) parent->left = left;
        else parent->right = left;
        parent->height = 1 + max(height(parent->left), height(parent->right));
    }
}

void AVL:: left_rotate(Node* node){
    Node *right = node->right;
    
    node->right = right->left;
    right->left = node;
    if(node->right != nullptr) node->right->parent = node;
    right->parent = node->parent;
    node->parent = right;

    node->height = 1+max(height(node->left), height(node->right));
    right->height = 1+max(height(right->left), height(right->right));
    
    if(right->parent == nullptr) root = right;
    else {
        Node* parent = right->parent;
        if(parent->left == node) parent->left = right;
        else parent->right = right;
        parent->height = 1 + max(height(parent->left), height(parent->right));
    }
}


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

    node->height = 1+ max(height(node->left), height(node->right));

    int balance = node->heightbalance();

    if (balance > 1 && data < node->left->data) right_rotate(node);
    else if (balance < -1 && data > node->right->data) left_rotate(node);
    else if (balance > 1 && data > node->left->data){
        left_rotate(node->left);
        right_rotate(node);
    }
    else if (balance <-1 && data < node->right->data){
        right_rotate(node->right);
        left_rotate(node);
    };
}

int main(){
    AVL tree;
    tree.insert(5, tree.root);
    tree.insert(8, tree.root);
    tree.insert(7, tree.root);
    tree.insert(4, tree.root);
    tree.insert(2, tree.root);

    tree.level_order();                                

return 0;
}