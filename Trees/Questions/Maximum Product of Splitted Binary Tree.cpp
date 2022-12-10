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
    int dfs(TreeNode* node, unordered_map<TreeNode*,int> &m){
        if (node == NULL) return 0;
        return m[node] = dfs(node->left,m)  + dfs(node->right,m)+ node->val;
    }
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        long total = dfs(root, m);
        long maxp = 0;
        for(auto i : m){
            long prod = (total - i.second)*i.second;
            if(prod>maxp) maxp = prod;
        }
        return maxp%1000000007;
    }
}; 
 
int main(){
    
 
return 0;
}