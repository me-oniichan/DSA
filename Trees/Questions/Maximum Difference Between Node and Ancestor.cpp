//Problem Statement : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int v = 0;
    void dfs(TreeNode* node, int mn, int mx){
        if (node == NULL) return;
        
        if(node->val - mn > v) v= node->val - mn;
        else if (mx-node->val > v) v = mx - node->val;

        if(node->val < mn) mn = node->val;
        else if(node->val > mx) mx = node->val;

        dfs(node->left, mn, mx);
        dfs(node->right, mn, mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        dfs(root->left, root->val, root->val);
        dfs(root->right, root->val, root->val);
        return v;
    }
}; 
 
int main(){
    
 
return 0;
}