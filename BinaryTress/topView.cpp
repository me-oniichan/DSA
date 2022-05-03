//HackerRank solution
//Question: https://www.hackerrank.com/challenges/tree-top-view/

#include<bits/stdc++.h>

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

    void topView(Node * root) {
        if(root == nullptr) return;
        int w = 0;
        map<int, int> m;
        map <Node*, int> mapTrack;
        queue<Node*> q;
        
        mapTrack[root] = 0;
        m[0] = root->data;
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            w = mapTrack[root];
            
            if (m.count(w) == 0){
                m[w] = root->data;
            }
            
            if(root->left){
                mapTrack[root->left] = w-1;
                q.push(root->left);
            }
            if(root->right){
                mapTrack[root->right] = w+1;
                q.push(root->right);
            }
            q.pop();
        }
        for (auto i = m.begin(); i != m.end(); i++) {
            cout << i -> second << " ";
        }
    }

}; //End of Solution