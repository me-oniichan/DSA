#include <bits/stdc++.h>
#include <cmath>
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
    int values, ans;
    void dfs(TreeNode *node){
        int map = 1<<node->val;
        values^=map;

        if (!node->left && !node->right){
            if (values == 0 || ceil(log2(values) == floor(log2(values)))){
                ans+=1;
            }
        }
        if (node->right) {
            dfs(node->right);
        }
        if (node->left) {
            dfs(node->left);
        }

        values^=map;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        values = 0;
        ans = 0;
        dfs(root);
        return  ans;
    }
};
