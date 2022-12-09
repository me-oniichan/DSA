//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if (root == NULL) return vec;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));


        while(!q.empty()){
            pair<TreeNode*, int> node = q.front();
            if(vec.size() != node.second+1) vec.push_back(vector<int>());
            vec[node.second].push_back(node.first->val);
            if (node.first->left) q.push(make_pair(node.first->left, node.second+1));
            if (node.first->right) q.push(make_pair(node.first->right, node.second+1));

            q.pop();
        }
        return vec;
    }
};
 
int main(){
    
 
return 0;
}