#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
    T val;
    Node(T val)
    {
        this->val = val;
    }
};

template <class T>
class BST
{
public:
    Node<T> *root = NULL;
    BST(Node<T> *root = NULL)
    {
        this->root = root;
    }

    Node<T> *search(T val){
        Node<T> * ptr = root;
        while(ptr != nullptr){
            if (ptr->val == val) return ptr;
            else if (ptr->val < val) ptr = ptr->right;
            else ptr = ptr->left;
        }
        return NULL;
    }

    void insert(T value){
        Node<T> *node = new Node<T>(value);
        Node<T> *parent = NULL;
        Node<T> *ptr = root;

        while (ptr != nullptr)
        {
            parent = ptr;
            if (ptr->val > node->val) ptr = ptr->left;
            else ptr = ptr->right;
        }

        node->parent = parent;
        if (parent == nullptr) root = node;
        else if (parent->val < node->val) parent->right = node;
        else parent->left = node;
    }

    void inOrder(Node<T>* node){
        if (node == nullptr) return;

        inOrder(node->left);
        cout<<node->val<<' ';
        inOrder(node->right);
    }

    void preOrder(Node<T>* node){
        if (node == nullptr) return;
        cout<<node->val<<' ';
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node<T> *node){
        if (node == nullptr) return;

        postOrder(node->left);
        postOrder(node->right);
        cout<<node->val<<' ';
    }
};

int main()
{
    BST<int> bst;
    bst.insert(6);
    bst.insert(2);
    bst.insert(22);
    bst.insert(3);
    bst.insert(-6);
    bst.insert(74);
    bst.insert(5675);
    bst.insert(678);
    cout<<(*bst.search(22)).val<<endl;
    bst.inOrder(bst.root);
    cout<<endl;
    bst.preOrder(bst.root);
    cout<<endl;
    bst.postOrder(bst.root);
    cout<<endl;

    BST<string> strBSt;
    strBSt.insert("one");
    strBSt.insert("eight");
    strBSt.insert("three");
    strBSt.insert("nine");
    strBSt.insert("two");
    strBSt.inOrder(strBSt.root);
    return 0;
}