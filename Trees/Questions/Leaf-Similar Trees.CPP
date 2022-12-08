//Problem Statement : https://leetcode.com/problems/leaf-similar-trees/

#include <iostream>
#include <vector>
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
    void inOrder(TreeNode* node, vector<int>& leaf){    
        if (node == NULL) return;

        inOrder(node->left,leaf);
        if(node->left == NULL && node->right == NULL) leaf.push_back(node->val);
        inOrder(node->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        inOrder(root1,leaf1);
        inOrder(root2,leaf2);
        return leaf1 == leaf2;
    }
};
 
int main(){
    
 
return 0;
}