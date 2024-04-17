#include <algorithm>
#include <bits/stdc++.h>
#include <string>
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
    string ans;
    
    void dfs(string &s, TreeNode *node){
        if (node == nullptr){
            return;
        }
        else if (node->left == nullptr && node->right == nullptr){
            s.push_back(node->val+'a');
            reverse(s.begin(), s.end());
            ans = min(ans, s);
            reverse(s.begin(), s.end());
        }
        else {
            s.push_back(node->val+'a');
            dfs(s, node->left);
            dfs(s, node->right);
        }

        s.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        string s = "";
        dfs(s, root);
        return ans;
    }
};
