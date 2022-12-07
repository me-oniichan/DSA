//Problem Statement : https://leetcode.com/problems/range-sum-of-bst/

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
    int sum = 0, low, high;
    void inOrder(TreeNode* node){    
        if (node == NULL) return;
        inOrder(node->left);
        if (node->val >= low && node->val <= high) sum+=node->val;
        inOrder(node->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        inOrder(root);
        return sum;
    }
}; 
 
int main(){
    
 
return 0;
}