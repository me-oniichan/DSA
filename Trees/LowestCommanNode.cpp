//Find the lowest common node for data v1 and v2
//Problem Statement: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    
    Node *lca(Node *root, int v1,int v2) {
        if (root == NULL) return new Node(-1);
        if(root->data == v1 || root->data == v2) return root;
        
        Node *node1 = lca(root->left, v1, v2);
        Node *node2 = lca(root->right, v1, v2);
        if (
                (node1 != nullptr || node2 != nullptr) &&( 
                (node1->data == v1 && node2->data == v2)||
                (node1->data == v2 && node2->data == v1))
            ) return root;
            
        else if ((node1 != NULL) && (node1->data == v1 || node1->data == v2)) return node1;
        else if ((node2 != NULL) && (node2->data == v1 || node2->data == v2)) return node2;
        
        if (node1->data != -1) return node1;
        else if (node2->data != -1) return node2;
        return new Node(-1);
    }

}; //End of Solution

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
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
