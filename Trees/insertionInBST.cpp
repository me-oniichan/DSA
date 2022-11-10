//Insertion in BST using iteration
//Problem statement: https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem


#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node *refr = root;
        while (refr!=nullptr) {
            if (refr->data > data){
                if (refr->left == nullptr){
                    refr->left = new Node(data);
                    return root;
                }
                refr = refr->left;
            }
            else{
                if(refr->right == nullptr){
                    refr->right = new Node(data);
                    return root;
                }
                refr = refr->right;
            }
        }
        root =  new Node(data);
        return root;
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
