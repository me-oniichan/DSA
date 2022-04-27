#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    
    Node(){};
    Node(int val){
        data = val;
    }
    
    void addLeftNode(int data){
        Node* temp = new Node(data);
        left = temp;
    }
    
    void addRightNode(int data){
        Node* temp = new Node(data);
        right = temp;
    }
};

void traverse(Node * node, vector<int> * arr)
{
    if (node == nullptr)
        return;
    arr->push_back(node->data);
    traverse(node->left, arr);
    traverse(node->right, arr);
    return;
}
vector<int> preorder(Node * root)
{
    vector<int> arr;
    traverse(root, &arr);
    return arr;
}


int main()
{
    Node root;
    root.data = 5;
    root.addLeftNode(10);
    root.addRightNode(20);

    // Preoder Traversal
    vector<int> preorderData = preorder(&root);
    for(vector<int> :: iterator ptr = preorderData.begin(); ptr < preorderData.end(); ptr++){
        cout<<*ptr<<" ";
    }
    cout<<endl;

return 0;
}