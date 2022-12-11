//Problem Statement : https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxm = INT_MIN;

    int dfs(TreeNode* node){
        if (!node) return INT_MIN;
        
        int left = dfs(node->left),right = dfs(node->right);
        int cur = 0;
        if(left>0) cur+=left;
        if(right>0) cur+=right;

        cur+=node->val;
        if(cur>maxm) maxm = cur;

        left = left == INT_MIN? 0:left;
        right = right == INT_MIN? 0:right;

        cur = max(max(left, right) + node->val, node->val);

        return cur;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxm;
    }
}; 
 
int main(){
    
 
return 0;
}