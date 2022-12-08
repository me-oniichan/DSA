//Problem Statement : https://leetcode.com/explore/featured/card/top-interview-questions-easy/94/trees/625/

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
    long prev;
    bool flag = 1;
    void inOrder(TreeNode* node){    
        if (node == NULL || !flag) return;

        inOrder(node->left);
        if (node->val > prev) prev  = node->val;
        else flag = 0;
        inOrder(node->right);
    }
    bool isValidBST(TreeNode* root) {
        prev = INT64_MIN;
        inOrder(root);
        return flag;
    }
};
 
int main(){
    
 
return 0;
}