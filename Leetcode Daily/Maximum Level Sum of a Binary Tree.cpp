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
    int maxLevelSum(TreeNode* root) {
        int ans=1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 1, maxsum = INT_MIN;
        int sum=0;
        while(true){
            auto node = q.front();
            q.pop();
            if(node == NULL){
                if(sum > maxsum){
                    maxsum = sum;
                    ans = level;
                }
                sum=0;
                if(q.empty()) break;
                level++;
                q.push(NULL);
                continue;
            }

            sum+=node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
        return ans;
    }
};