#include <bits/stdc++.h>
#include <cstddef>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
	   if (!root) return nullptr;	   
	   queue<Node*> q;
	   q.push(root);
	   q.push(NULL);
	   Node *prev = NULL;
	   while (q.size() > 1){
		  auto ptr = q.front();
		  q.pop();

		  if (ptr == nullptr ){
			 q.push(NULL);
			 prev = NULL;
			 continue;
		  }

		  if (prev != nullptr){	 
			 prev->next = ptr;
		  }

		  prev = ptr;

		  if (ptr->left) q.push(ptr->left);
		  if (ptr->right) q.push(ptr->right);
		  

		  
	   }

	   return root;
    }
};
