//Problem Statement : https://leetcode.com/explore/featured/card/top-interview-questions-easy/94/trees/627/
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
    bool check(TreeNode* node1, TreeNode* node2){
        if (!node1 && !node2) return true;
        else if(!node1 || !node2) return false; 

        if (node1->val != node2->val) return false;
        return check(node1->left, node2->right) && check(node1->right, node2->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
};