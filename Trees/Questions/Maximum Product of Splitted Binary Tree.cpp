//Problem Statement : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/submissions/

#include <bits/stdc++.h>
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
    long total = 0, maxp = 0;
    long sum(TreeNode* node){
        if (node == NULL) return 0;
        return (node->val + sum(node->left) + sum(node->right));
    }

    int dfs(TreeNode* node){
        if (node == NULL) return 0;
        int s = dfs(node->left) + dfs(node->right) + node->val;
        maxp = max(maxp, (total - s)*s);
        return s;
    }

    int maxProduct(TreeNode* root) {
        total = sum(root);
        dfs(root);
        return maxp%1000000007;
    }
}; 
 
int main(){
    
 
return 0;
}