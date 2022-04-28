//Printing values of binary tree on same height
//Problem Statement : https://www.hackerrank.com/challenges/tree-level-order-traversal

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
/*
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

    void levelOrder(Node * root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            cout<<root->data<<' ';
            if(root->left){
                q.push(root->left);
            }
            if (root->right) {
                q.push(root->right);
            }
            q.pop();
        }
    }

}; //End of Solution
