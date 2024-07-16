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

class Solution{
    public:

    TreeNode* mostCommonAncestor(TreeNode* root, int p, int q){
        if(root == NULL) return NULL;
        if(root->val == p || root->val == q) return root;

        TreeNode* left = mostCommonAncestor(root->left, p, q);
        TreeNode* right = mostCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL) return root;
        if(left == NULL && right == NULL) return NULL;

        return left != NULL ? left : right;
    }

    bool findPath(TreeNode* root, int value, string &path){
        if(root == NULL) return false;
        if(root->val == value) return true;

        path.push_back('L');
        bool res = findPath(root->left, value, path);
        if(res) return true;
        path.pop_back();
        path.push_back('R');
        res = findPath(root->right, value, path);
        if(res) return true;

        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* Node, int startValue, int destValue){
        string path = "";
        TreeNode* ancestor = mostCommonAncestor(Node, startValue, destValue);
        TreeNode* temp = ancestor;
        
        findPath(temp, startValue, path);
        for(int i = 0; i < path.size(); i++){
            path[i]='U';
        }
        findPath(temp, destValue, path);

        return path;
    }
};
